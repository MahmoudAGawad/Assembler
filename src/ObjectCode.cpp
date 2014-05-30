/*
 * ObjectCode.cpp
 *
 *  Created on: May 30, 2014
 *      Author: MahmoudSaleh
 */

#include "ObjectCode.h"

/*

 nmsek el operand:
 nshof law # aw @ aw = aw c aw x

 law + tb2a 5alsa

 law word tb2a 5alsa

 law c tb2a 5alsa

 law x  tb2a 5alsa

 law #rakam yb2a nscheck law el rakam y fit f el

 el operand dyman hayb2a expression except for: array,x | Regsiters operation(format 2) |
 hansheel el #,@ hayb2a expression 3ady

 >> 1000-90*10

 special case lw "*"? program counter!
 */
string ObjectCode::operandProccessing(string operand, int pc) {
	char c = operand[0];
	unsigned l = 1;
	if (c == '#') {
		this->i = 1, this->n = 0;
	} else if (c == '@') {
		this->n = 1, this->i = 0;
	} else if (c == '=') {

	} else
		l = 1;

	string label = "", out = "";
	vector<string> infix;
	int len = operand.length();
	for (; l < len; l++) {
		label.clear();
		while ((operand[l] >= 'a' && operand[l] <= 'z')
				|| (operand[l] >= 'A' && operand[l] <= 'Z')) {
			label.append(&operand[l++]);
		}
		if (label.length() > 0) {
			infix.push_back(symbolTable->get(label));
			continue;
		}

		// operation: + - * /
		if (operand[l] == '+' || operand[l] == '-' || operand[l] == '/') {
			infix.push_back(operand.substr(l, l + 1));
		} else if (operand[l] == '*') {
			if (l > 0 && operand[l - 1] != '+' && operand[l - 1] != '-'
					&& operand[l - 1] != '*' && operand[l - 1] != '/'
					&& l < operand.length() - 1 && operand[l + 1] != '+'
					&& operand[l + 1] != '-' && operand[l + 1] != '*'
					&& operand[l + 1] != '/') {
				// '*' is operation
				infix.push_back(operand.substr(l, l + 1));
			} else {
				infix.push_back(General::intToString(pc));
			}

		}

		// C'string' & X'A21'
		else if (toupper(operand[l]) == 'C') {
			l += 2;
			int tt;
			while (operand[l] != '\'') {
				if (operand[l] < 'a')
					tt = operand[l] - 'A';
				else
					tt = operand[l] - 'a';
				out += General::decimalToHexa(tt);
				l++;
			}
			return out;
		} else if (toupper(operand[l]) == 'X') {
			l += 2;
			while (operand[l] != '\'') {
				out += operand[l++];
			}
			return out;
		}

	}

	return out;

}

void ObjectCode::operationProcessing(string operation) {
	operation = General::toUpper(operation);
	if (operation == "RESB" || operation == "RESW" || operation == "LTORG"
			|| operation == "EQU" || operation == "ORG") {
		// has no objcode
	} else {

		HashTable<string, operationInfo> opTable;

		operationInfo opTemp = opTable.get(operation);

		string opcode = opTemp.getOpCode();
		int value = atoi(opcode.c_str());

		int bin = General::hexaToBinary(opcode); // hex to binary

		stringstream ss;
		ss << bin;
		string str = ss.str();

		str.at(str.length() - 2) = n;
		str.at(str.length() - 1) = i;

		// char hex[20],c;
		// binary_hex(n,hex);

	}
}
