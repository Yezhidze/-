#pragma once
#include <iostream>
#include <string>
#include <fstream> 
using namespace std;
class Management
{
private:
	string name;
	string content; //содержание 
public:
	virtual ~Management() = default;

	Management(string p_name_File) : name(p_name_File), content("") {}
	string getName() const { return name; }
	string getContent() const { return content; }

	bool create()
	{
		ofstream file(name);
		if (file.is_open()) { file.close(); return true; }	return false;
	}

	bool open()
	{
		ifstream file(name);
		if (file.is_open())
		{
			content = string((istreambuf_iterator<char>(file)),
				istreambuf_iterator<char>());
			file.close();
			return true;
		}
		return false;
	}

	bool Save()
	{
		ofstream file(name);
		if (file.is_open()) { file << content; file.close(); return true; }return false;
	}

	void setContent(const string& newContent)
	{
		content = newContent;
	}

	bool SaveAsNew(const string& newName)
	{
		ofstream file(newName);
		if (file.is_open()) { file << content; file.close(); return true; }return false;
	}

	bool printing_doc()
	{
		ifstream file(name);
		if (file.is_open())
		{
			content = string((istreambuf_iterator<char>(file)),
				istreambuf_iterator<char>());
			file.close();
			return true;
		}
		return false;
	}
};

