// Huffman Coding | Moshiur_1602022

#include <bits/stdc++.h>
using namespace std;

// A Huffman tree node
struct MinHeapNode {
	char data;
	unsigned freq;
	MinHeapNode *left, *right;
	MinHeapNode(char data, unsigned freq)
	{
		left = right = NULL;
		this->data = data;
		this->freq = freq;
	}
};

// Comparer
struct compare {
	bool operator()(MinHeapNode* l, MinHeapNode* r)
	{
		return (l->freq > r->freq);
	}
};

// printing
void printCodes(struct MinHeapNode* root, string str)
{
	if(!root)
		return;
	if(root->data != '$')
		cout << root->data << ": " << str << "\n";

	printCodes(root->left, str + "0");
	printCodes(root->right, str + "1");
}

// Building huffman tree
void HuffmanCodes(char data[], int freq[], int size)
{
	struct MinHeapNode *left, *right, *top;
	priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;

	for (int i = 0; i < size; ++i)
		minHeap.push(new MinHeapNode(data[i], freq[i]));

	while (minHeap.size() != 1) {
		left = minHeap.top();
		minHeap.pop();

		right = minHeap.top();
		minHeap.pop();

		top = new MinHeapNode('$', left->freq + right->freq);

		top->left = left;
		top->right = right;

		minHeap.push(top);
	}

	printCodes(minHeap.top(), "");
}


int main()
{
    freopen("input_huffman.txt","r",stdin);
    freopen("output_huffman.txt","w",stdout);

    string s;
    getline(cin, s);

    set<char> st;
    map<char, int> mp;
    for(int i=0; i<s.size(); i++){
        st.insert(s[i]);
        mp[s[i]]++;
    }

    int n = st.size(), i = 0;
    char str[n];
    int freq[n];
    for(auto &x : st){
        str[i] = x;
        freq[i] = mp[x];
        i++;
    }

	HuffmanCodes(str, freq, n);

	return 0;
}
