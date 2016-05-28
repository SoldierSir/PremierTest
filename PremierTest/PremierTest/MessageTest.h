#pragma once
#include <set>
using namespace std;
class Folder;
class MessageTest
{
public:
	MessageTest(void);
	virtual ~MessageTest(void);
public:
	MessageTest(const std::string &str = ""):
	  contents(str){}
	MessageTest(const MessageTest&m):
	  contents(m.GetContents()),folders(m.GetFolders())
	  {
		  put_Msg_in_Folders(folders);
	  }
	MessageTest &operator = (const MessageTest&);
	void Save(Folder&);
	void Remove(Folder&);
public:
	std::string GetContents() const { return contents; }
	void SetContents(std::string val) { contents = val; }
	std::set<Folder*> GetFolders() const { return folders; }
	void SetFolders(std::set<Folder*> val) { folders = val; }
private:
	void put_Msg_in_Folders(const std::set<Folder*>&rhs);
	void Remove_Msg_From_Folders();
private:
	std::string contents;
	std::set<Folder*> folders;
};

