/**
 * Morse Tree Class
 * CS3434 Data Structures
 */

#include <iostream>
#include <fstream>
#include <string>

class MorseTree {
private:
	struct Node
	{
		char value;
		Node* dot;
		Node* dash;
		Node(char v, Node* dt, Node* ds) : value(v), dot(dt), dash(ds) {}
	};
	Node* root;

	void addNode(char v, std::string sub_morse, Node* start) {
		// std::cout << v << '\t'<< sub_morse.empty() << std::endl;
		if (sub_morse.empty()) {
			start->value = v; return;
		}

		// Node** next = ((sub_morse.substr(1))[0] == '.') ? &(*start).dot : &(*start).dash;
		// std::cout << v << '\t'<< sub_morse.substr(1) <<'\t' << next << std::endl;

		// if(&next == nullptr) *next = new Node((char)NULL,nullptr,nullptr);
		// addNode(v, sub_morse.substr(1), *next);

		if(sub_morse[0] == '.') {
			if(start->dot == nullptr)
				start->dot = new Node((char)NULL,nullptr,nullptr);
			addNode(v,sub_morse.substr(1),start->dot);
		}
		else if(sub_morse[0] == '-') {
			if(start->dash == nullptr)
				start->dash = new Node((char)NULL,nullptr,nullptr);
			addNode(v,sub_morse.substr(1),start->dash);
		}
	}

	void addNode(char v, std::string morse) {
		addNode(v, morse, root); 
	}


public:
	MorseTree(const std::string& filename) {
		root = new Node((char)NULL,nullptr,nullptr);
		std::ifstream ifs(filename);
	    for (std::string line; std::getline(ifs, line); )
	    {
	        addNode(line[0], line.substr(2));
	    }
	}
	~MorseTree() {}

	void ioTraversal(Node* node, std::string path) {
		if (node == nullptr && node != root) return;
		ioTraversal(node->dot, path.append("."));
		if(node->value) std::cout << node->value << '\t' << path << std::endl;
		ioTraversal(node->dash, path.append("-"));
	}

	void to_string() {
		ioTraversal(root, "");
	}

	/* data */
};