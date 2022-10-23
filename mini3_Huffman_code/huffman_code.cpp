// ta 課、與同學討論
#include <iostream>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;


struct Item
{
    int index;
    int value;
};

struct Node
{
    struct Node *left = nullptr;
    struct Node *right = nullptr;
    struct Item data;


};

struct Hash
{
    struct Item data;
    string code;
};


struct node_cmp
{
    bool operator()(const struct Node* a, const struct Node* b)
    {
        return a->data.value > b->data.value;
    }
};

struct table_cmp
{
    bool operator()(const struct Hash a, const struct Hash b)
    {
        return a.data.index < b.data.index;
    }
};



Node* huffman_code(struct Node** NodeArr, int N)
{
    // make priority queue;
    priority_queue<struct Node*, vector<struct Node*>, node_cmp > nodeQue;
    for(int i = 0; i < N; i++)
    {
        nodeQue.push(NodeArr[i]);
    }
    
    // build tree
    Node* root = nullptr;
    while(nodeQue.size() > 1 )
    {
        struct Node* node1 = nodeQue.top();
        nodeQue.pop();
        struct Node* node2 = nodeQue.top();
        nodeQue.pop();
        root = new Node;
        root->data.value = node1->data.value + node2->data.value;
        root->left = node1;
        root->right = node2;
        nodeQue.push(root);
    }
    return root;   
}

void printInorder(Node* root, string s, Hash* table)
{
    static int i = 0;
    if(root->left == nullptr && root->right == nullptr)
    {
        //cout << s << "-->" << root->data.value << endl;
        table[i].code = s;
        table[i].data = root->data;
        i++;
        return;
    }    
    
    if(root->left != nullptr)
    {
        printInorder(root->left, string(s+"0"), table);
    }
    if(root->right != nullptr)
    {
        printInorder(root->right, string(s+"1"), table);
    }
    
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N;
    cin >> N;
    struct Node** NodeArr = (struct Node**)malloc(sizeof(struct Node*) * N);
    int index = 1;
    for(int i = 0; i < N; i++)
    {
        struct Node* temp = new Node();
        cin >> temp->data.value;
        temp->data.index = index++;
        NodeArr[i] = temp;
    }

    struct Node* root = huffman_code(NodeArr, N);

    

    if( N == 1)
    {
        cout << "0" << '\n';
        return 0;
    }
    // query
    Hash* table = new Hash[N];

    
    printInorder(root, string(""), table);
    

    sort(table, table + N, table_cmp() );

    for(int i = 0; i<N;i++)
    {
        cout << table[i].code  << '\n';
    }





        
    return 0;
}