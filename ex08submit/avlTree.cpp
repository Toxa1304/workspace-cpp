#include <iostream>
#include <sstream>
#include <string.h>

// C++ program to insert a node in AVL tree  

using namespace std; 
int compare_general(char a[], char b[]);
int compare_lexicographically(char a[], char b[]);

int str_length(char* mystring) {
	int i = 0;
	while (mystring[i] != '\0') {
		i++;
	}
	return i;
}
//1 - LEX
//2 - SHORTLEX
//3 - COLEX
int mode = 0;
// An AVL tree node  
class Node  
{  
    public: 
    char key[52];  
    Node *left;  
    Node *right;  
    int height; 
    int badness; 
};  
  
// A utility function to get maximum 
// of two integers  
int max(int a, int b);  
  
// A utility function to get the  
// height of the tree  
int height(Node *N)  
{  
    if (N == NULL)  
        return 0;  
    return N->height;  
}  
  
// A utility function to get maximum 
// of two integers  
int max(int a, int b)  
{  
    return (a > b)? a : b;  
}  
  
/* Helper function that allocates a  
   new node with the given key and  
   NULL left and right pointers. */
Node* newNode(char key[])  
{  
    Node* node = new Node(); 

    string bufferString = key;
    for(int i =0; i< bufferString.length();i++){
        node->key[i]= key[i];
    }
    node->key[bufferString.length()] = '\0';

    node->left = NULL;  
    node->right = NULL;  
    node->badness = 1;
    node->height = 1; // new node is initially 
                      // added at leaf  
    return(node);  
}  
  
// A utility function to right 
// rotate subtree rooted with y  
// See the diagram given above.  
Node *rightRotate(Node *y)  
{  
    Node *x = y->left;  
    Node *T2 = x->right;  
  
    // Perform rotation  
    x->right = y;  
    y->left = T2;  
  
    // Update heights  
    y->height = max(height(y->left), 
                    height(y->right)) + 1;  
    x->height = max(height(x->left), 
                    height(x->right)) + 1;  
  
    // Return new root  
    return x;  
}  
  
// A utility function to left  
// rotate subtree rooted with x  
// See the diagram given above.  
Node *leftRotate(Node *x)  
{  
    Node *y = x->right;  
    Node *T2 = y->left;  
  
    // Perform rotation  
    y->left = x;  
    x->right = T2;  
  
    // Update heights  
    x->height = max(height(x->left),     
                    height(x->right)) + 1;  
    y->height = max(height(y->left),  
                    height(y->right)) + 1;  
  
    // Return new root  
    return y;  
}  
  
// Get Balance factor of node N  
int getBalance(Node *N)  
{  
    if (N == NULL)  
        return 0;  
    return height(N->left) - height(N->right);  
}  
  
// Recursive function to insert a key 
// in the subtree rooted with node and 
// returns the new root of the subtree.  
Node* insert(Node* node, char key[])  
{  
    /* 1. Perform the normal BST insertion */
    if (node == NULL)  
        return(newNode(key));  
  
    if (compare_general(key, node->key)==-1) 
        node->left = insert(node->left, key);  
    else if (compare_general(key, node->key)==1)  
        node->right = insert(node->right, key);  
    else{ // Equal keys are not allowed in BST 
        node->badness = node->badness+1; 
        return node;  
    }
    /* 2. Update height of this ancestor node */
    node->height = 1 + max(height(node->left),  
                        height(node->right));  
  
    /* 3. Get the balance factor of this ancestor  
        node to check whether this node became  
        unbalanced */
    int balance = getBalance(node);  
  
    // If this node becomes unbalanced, then  
    // there are 4 cases  
  
    // Left Left Case  
    if (balance > 1 && compare_general(key, node->left->key) == -1)  
        return rightRotate(node);  
  
    // Right Right Case  
    if (balance < -1 && compare_general(key, node->right->key)== 1)  
        return leftRotate(node);  
  
    // Left Right Case  
    if (balance > 1 && compare_general(key, node->left->key)== 1)  
    {  
        node->left = leftRotate(node->left);  
        return rightRotate(node);  
    }  
  
    // Right Left Case  
    if (balance < -1 && compare_general(key, node->right->key)==-1)  
    {  
        node->right = rightRotate(node->right);  
        return leftRotate(node);  
    }  
  
    /* return the (unchanged) node pointer */
    return node;  
}  
  
// A utility function to print preorder  
// traversal of the tree.  
// The function also prints height  
// of every node  
void preOrder(Node *root)  
{  
    if(root != NULL)  
    {  
        cout << root->key << " ";  
        preOrder(root->left);  
        preOrder(root->right);  
    }  
}  
  
// Driver Code
Node * minValueNode(Node* node)  
{  
    Node* current = node;  
  
    /* loop down to find the leftmost leaf */
    while (current->left != NULL)  
        current = current->left;  
  
    return current;  
} 
Node* deleteNode(Node* root, char * key)  
{  
      
    // STEP 1: PERFORM STANDARD BST DELETE  
    if (root == NULL)  
        return root;  
  
    // If the key to be deleted is smaller  
    // than the root's key, then it lies 
    // in left subtree  
    if ( compare_lexicographically(key, root->key) == -1 ) 
        root->left = deleteNode(root->left, key);  
  
    // If the key to be deleted is greater  
    // than the root's key, then it lies  
    // in right subtree  
    else if( compare_lexicographically(key, root->key) == 1)  
        root->right = deleteNode(root->right, key);  
  
    // if key is same as root's key, then  
    // This is the node to be deleted  
    else
    {  
        // node with only one child or no child  
        if((root->left == NULL) || (root->right == NULL) )  
        {  
            Node *temp = root->left ? root->left : root->right;  
  
            // No child case  
            if (temp == NULL)  
            {  
                temp = root;  
                root = NULL;  
            }  
            else // One child case  
            *root = *temp; // Copy the contents of  
                           // the non-empty child  
            free(temp);  
        }  
        else
        {  
            // node with two children: Get the inorder  
            // successor (smallest in the right subtree)  
            Node* temp = minValueNode(root->right);  
  
            // Copy the inorder successor's  
            // data to this node  
            int i;
            for ( i = 0; i < str_length(temp->key); i++) {
                root->key[i] = temp->key[i];  
            }
            root->key[i] = '\0';
            root->badness = temp->badness;    
  
            // Delete the inorder successor  
            root->right = deleteNode(root->right, temp->key);  
        }  
    }  
  
    // If the tree had only one node 
    // then return  
    if (root == NULL)  
    return root;  
  
    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE  
    root->height = 1 + max(height(root->left),  
                           height(root->right));  
  
    // STEP 3: GET THE BALANCE FACTOR OF  
    // THIS NODE (to check whether this  
    // node became unbalanced)  
    int balance = getBalance(root);  
  
    // If this node becomes unbalanced,  
    // then there are 4 cases  
  
    // Left Left Case  
    if (balance > 1 &&  
        getBalance(root->left) >= 0)  
        return rightRotate(root);  
  
    // Left Right Case  
    if (balance > 1 &&  
        getBalance(root->left) < 0)  
    {  
        root->left = leftRotate(root->left);  
        return rightRotate(root);  
    }  
  
    // Right Right Case  
    if (balance < -1 &&  
        getBalance(root->right) <= 0)  
        return leftRotate(root);  
  
    // Right Left Case  
    if (balance < -1 &&  
        getBalance(root->right) > 0)  
    {  
        root->right = rightRotate(root->right);  
        return leftRotate(root);  
    }  
  
    return root;  
} 
void printInorder(Node* node) { 
    if (node == NULL) 
    return; 
    printInorder(node->left); 
    cout << "(";
    for (int i = 0 ; i < str_length(node->key); i++)
        cout << node->key[i];
    cout << "," << node ->badness;
    cout << ") ";
    
    
         
    printInorder(node->right);  
}

int compare_char_noCaps(char a, char b){
    //cout <<"COMPARE NOCAPS ENTERED" << endl;
    bool aUpper = false;
    bool bUpper = false;
    //make both letters lowercase
    if((int)a < 91&&(int)a > 64){
        aUpper = true;
        a = a + 32;
        //cout<< ("char  a is upper!!")<< endl;
    }
    if((int)b < 91&&(int)b > 64){
        bUpper = true;
        b = b + 32;
        //cout<< ("char  b is upper!!")<< endl;
    }
    if(a<b){
        return -1;
    }
    if(a>b){
        return 1;
    }
    else{
        return 0;
    }
}
int compare_caps(char a, char b){
    //cout <<"COMPARE CAPS ENTERED" << endl;
    bool aUpper = false;
    bool bUpper = false;
    if((int)a < 91&&(int)a > 64){
        aUpper = true;
        a = a + 32;
        //cout<< ("char  a is upper!!")<< endl;
    }
    if((int)b < 91&&(int)b > 64){
        bUpper = true;
        b = b + 32;
        //cout<< ("char  b is upper!!")<< endl;
    }
    if(aUpper==true&&bUpper==false){
        return -1;
        }
    if(aUpper==false&&bUpper==true){
        return 1;
    }
    else{
        return 0;
    }
}

int compare_lexicographically(char a[], char b[]){

    string stringA = a;
    string stringB = b;

    int lenA = stringA.length();
    int lenB = stringB.length();
    int minLen = 0;
    if(lenA<lenB||lenA==lenB){
        minLen = lenA;
    }
    else{
        minLen = lenB;
    }
    //cout<< "MINLEN IS: " << minLen << endl;
        int i = 0;
        while(i<minLen){
            int result = compare_char_noCaps(a[i],b[i]);
            if(result == -1){
                return -1;
            }
            if (result == 1){
                return 1;
            }
            if(i==minLen-1&&result ==0){
                if(lenA<lenB){
                    return -1;
                }
                if(lenA>lenB){
                    return 1;
                }
                int j =0;
                while(j<minLen){
                    int resultt = compare_caps(a[j], b[j]);
                    if(resultt == -1){
                        return -1;
                    }
                    if (resultt == 1){
                        return 1;
                    }
                    if(j == minLen-1 && resultt == 0){
                        return 0;
                    }
                    j++;    
                    
                }
            }
            i++;
        }
    return 500;
}
int compare_shortlex(char a[], char b[]){
    string stringA = a;
    string stringB = b;
    int lenA = stringA.length();
    int lenB = stringB.length();
    if(lenA < lenB){
        return -1;
    }
    if (lenB < lenA){
        return 1;
    }
    else{
        return compare_lexicographically(a,b);
    }
}
int compare_colex(char a[], char b[]){
    string stringA = a;
    string stringB = b;
    int lenA = stringA.length();
    int lenB = stringB.length();
    char reverseA[lenA];
    char reverseB[lenB];
    int j =0;
    for(int i =lenA-1; i>=0; i--){
        reverseA[j] = a[i];
        //cout << "the char A reversed is: " << a[i]<< endl;
        j++;
    }
    j = 0;
    for(int i =lenB-1; i>=0; i--){
        reverseB[j] = b[i];
        //cout << "the char B reversed is: " << b[i]<< endl;
        j++;
    }
    reverseB[lenB] = '\0';
    reverseA[lenA] = '\0';
    // for(int i=0; i<= lenA; i++){
    //     cout << reverseA[i];
    // }
    // cout << endl;
    // for(int i=0; i<= lenB; i++){
    //     cout << reverseB[i];
    // }
   // cout << endl;
    return compare_lexicographically(reverseA, reverseB);
}
int compare_general(char a[], char b[]){
    if (mode ==1){
        return compare_lexicographically(a, b);
    }
    if(mode == 2){
        return compare_shortlex(a,b);
    }
    if (mode ==3){
        return compare_colex(a,b);
    }
    else{
        return 500;
    }
}
int badnessGlobal = 0;
void getNode(char a[], Node* root){
    if(root == NULL){
        return;
    }
    if (compare_general(a, root->key)==0){
        badnessGlobal = root->badness;
        return; 
    }
    if(compare_general(a, root->key)==-1){
        getNode(a, root->left); 
    }
    else{     
        getNode(a, root->right);  
    }
}

void printInorder2(Node* node, char b[]) { 
    if (node == NULL) 
    return; 
    printInorder2(node->left,b); 

    if(compare_general(b, node->key)==1){
        cout << "(";
        for (int i = 0 ; i < str_length(node->key); i++)
            cout << node->key[i];
        cout << "," << node ->badness;
        cout << ") ";
    }  
    printInorder2(node->right, b);  
}

void printInorder3(Node* node, char a[]) { 
    if (node == NULL) 
    return; 
    printInorder3(node->left,a); 

    if(compare_general(a, node->key)==-1){
        cout << "(";
        for (int i = 0 ; i < str_length(node->key); i++)
            cout << node->key[i];
        cout << "," << node ->badness;
        cout << ") ";
    }  
    printInorder3(node->right, a);  
}
void printInorder4(Node* node, char a[],char b[]) { 
    if (node == NULL) 
    return; 
    printInorder4(node->left,a,b); 

    if(compare_general(a, node->key)==-1 && compare_general(b, node->key)==1){
        cout << "(";
        for (int i = 0 ; i < str_length(node->key); i++)
            cout << node->key[i];
        cout << "," << node ->badness;
        cout << ") ";
    }  
    printInorder4(node->right, a,b);  
}
void dump(char a[], char b[], Node* node){
    if(a[0]=='_' && b[0]=='_'){
        printInorder(node);
        //cout << endl;
        return;
    }
    else if(a[0]=='_' ){
        printInorder2(node,b);
        return;
    }
    else if(b[0]=='_'){
        printInorder3(node,a);
        return;
    }
    else{
        printInorder4(node, a, b);
        return;
    }
}
void printPath(char a[], Node* node){
    if(node == NULL){
        return;
    }
    if(compare_general(a, node->key)==0){
        return;
    }
    if(compare_general(a,node->key)== -1){
        cout<< "L";
        printPath(a, node->left);
    }
    else if(compare_general(a,node->key)== 1){
        cout<< "R";
        printPath(a, node->right);
    }
}
bool nodeFound = false;
void findNode(char a[], Node* node){
    if (node == NULL){
    return; 
    }
    if(compare_general(a, node->key)==0){
        nodeFound= true;
        return;
    }
    if(compare_general(a,node->key)== -1){
        findNode(a, node->left);
    }
    else if(compare_general(a,node->key)== 1){ 
        findNode(a, node->right);
    }
}
int main() {
    int lineCounter = 0;
    int insertCounter = 0, loopCounter = 0;;
    string input, type, operation, value;
    int parent, val;
    cin >> type;
    lineCounter++;
    if (type.compare("LEX") == 0) {
        mode = 1;
    }
    else if (type.compare("SHORTLEX") == 0) {
        mode = 2;
    }
    else if (type.compare("COLEX") == 0) {
        mode = 3;
    }

    Node *root = NULL;  
    while (getline(cin, input)) {
		istringstream stringstream(input);
		stringstream >> operation;
        if ( operation.compare("I") == 0) {
            lineCounter++;
            while (stringstream) {
                if (loopCounter == 0) {
                    stringstream >> value;
                    loopCounter++;
                    continue;
                }
                // cout << value << endl;
                
                
                
                char something[value.length() + 1];

                strcpy(something, value.c_str());
                something[value.length()] = '\0';
                root = insert(root, something);
                stringstream >> value;

            }
            
            loopCounter = 0;
            // for (int i = 0; i < strlen(root->left->key); i++)
            //     cout << root->left->key[i];
            // cout<<endl;
        }
        else if (operation.compare("G") == 0) {
            badnessGlobal =0;
            lineCounter++;
           
            stringstream >>value;
            char something[value.length()+1];
            strcpy(something, value.c_str());
            getNode(something, root);
            cout <<lineCounter<<" "<< "(" << something << "," << badnessGlobal << ")" << endl;
            
            // something here
        }
        else if (operation.compare("E") == 0) {
            lineCounter++;
            
            while (stringstream) {
                if (loopCounter == 0) {
                    stringstream >> value;
                    loopCounter++;
                    continue;
                }
                char something[value.length() + 1];
                strcpy(something, value.c_str());
                root = deleteNode(root, something);
                stringstream >> value;
            }
            loopCounter = 0;
            //cout  << endl << endl; 
            // for (int i = 0; i < strlen(root->key); i++)
            //     cout << root->key[i] ;
            // cout << " - this is root node now!" << endl;    
            //printInorder(root);
        }
        else if (operation.compare("L") == 0) {
            lineCounter++;
            cout << lineCounter << " ";
            stringstream >> value;
            char something[value.length()+1];
            strcpy(something, value.c_str());
            
            findNode(something, root);
            
            

            if(nodeFound==true){
                cout << "*";
                printPath(something, root);
                nodeFound= false;
                cout << endl;
            }
            else{
                cout << "N";
                cout << endl;
            }
            
            // something here
        }
        else if (operation.compare("D") == 0) {
            lineCounter++;
            string a;
            string b;
            stringstream >> a;
            stringstream >> b;
            char something1[a.length() + 1];
            char something2[b.length() + 1];
            strcpy(something1, a.c_str());
            strcpy(something2, b.c_str());
            //cout << a << b<<endl;
            cout << lineCounter << " ";
            dump(something1, something2, root);
            cout << endl;
               
            
               
        }
        else if (operation.compare("F") == 0) {
            lineCounter++;
            return -1;
        }  
    } 


// char a[] = "abb";
// char b[] = "abc";
// char aaa = 'A';
// char bbb = 'b';
// const char* aa = "b";
// const char* bb = "A";

// int result = compare_lexicographically(a,b);
// cout << "COMPARISON: " << result<<endl;


//  d.insertInit(10,"10");

//  d.insertInit(20,"20");
//  d.insertInit(30,"30");
//  d.insertInit(40,"40");
//  d.insertInit(50,"50");
//  d.insertInit(25,"25");


 return 0;
}