#ifndef List_H
#define List_H
#include "Worker.h"
class List {
public:
	List();
	~List();
	Worker* first;
	friend ostream& operator<<(ostream& stream, const List& p);
	void add(string x, string y, int z, int w);
	void choose();
	int delete_chos();
	int add_from_file();
};
#endif // !List_H