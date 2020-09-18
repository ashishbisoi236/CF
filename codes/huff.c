string decodeHuffmanData(struct MinHeapNode* root, string binaryString)
{
    // Code here
    MinHeapNode *temp = root;
    string dc;
    int i= 0;
    while(binaryString[i]) {
        if(temp->left == NULL && temp->right == NULL) {
            dc.push_back(temp->data);
            temp = root;
        }
        else if(binaryString[i] == '0') {
            temp = temp->left;
            i++;
        }
        else if(binaryString[i] == '1') {
            temp = temp->right;
            i++;
        }
    }
    return dc;
}