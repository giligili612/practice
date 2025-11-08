#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <ostream>
#include <string>

class Document
{
public:
	Document(const std::string& title = "Untitled");
	void SetTitle(const std::string& title);
	const std::string& GetTitle() const;
	void AddContent(const std::string& content);
	void DeleteContent();
	const std::string& GetContent() const;
	bool isEmpty();

	friend std::ostream& operator<<(std::ostream& os, const Document& obj)
	{
		return os << obj.m_Content;
	}
private:
	std::string m_Title{};
	std::string m_Content{};
};

#endif
