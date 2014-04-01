/**
 * Morse Tree Class
 * CS3434 Data Structures
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class MorseTree {
public:
	struct Node
	{
		char value;
		Node* dot;
		Node* dash;
		Node(char v, Node* dt, Node* ds) : value(v), dot(dt), dash(ds) {}
	};
private:
	Node* root;
	std::vector<std::string> table = std::vector<std::string> (255," ");

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
		// table = new 

		std::ifstream ifs(filename);
	    for (std::string line; std::getline(ifs, line); )
	    {
	        addNode(line[0], line.substr(2));
	        table[line[0]] = line.substr(2);
	    }
	}

	~MorseTree() {}


	// //will take Node* as argument
	// void ioTraversal(Node* node, function func) {
	// 	if (node == nullptr) return;
	// 	ioTraversal(node->dot, path+".");
	// 	if(node->value) std::cout << node->value << '\t' << path << std::endl;
	// 	ioTraversal(node->dash, path+"-");
	// }

	void ioTraversal(Node* node, std::string path) {
		if (node == nullptr) return;
		ioTraversal(node->dot, path+".");
		if(node->value) std::cout << node->value << '\t' << path << std::endl;
		ioTraversal(node->dash, path+"-");
	}

	void to_string() {
		ioTraversal(root, "");
	}

	std::string encode(std::string text) {
		std::string r = std::string();

		for(std::string c = text; !c.empty(); c = c.substr(1)) {
			r += table[(int)toupper(c[0])];
			r += ' ';
		}
		return r;
	}

	std::string decode(std::string morse) {
		std::string r = std::string();
		Node* n = root;
		for(std::string c = morse; !c.empty(); c = c.substr(1)) {
			if(c[0] == '.') {
				n = n->dot;
			}
			if(c[0] == '-') {
				n = n->dash;
			}
			if(c[0] == ' ') {
				r += n->value;
				r += " ";
				n = root;
			}
		}
		return r;
	}

	/* data */
};