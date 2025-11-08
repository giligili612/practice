#include "Document.h"

Document::Document(const std::string& title)
{
	m_Title = title;
}
void Document::SetTitle(const std::string& title)
{
	m_Title = title;
}
const std::string& Document::GetTitle() const
{
	return m_Title;
}
void Document::AddContent(const std::string& content)
{
	if(!m_Content.empty())
		m_Content += "\n";
	m_Content += content;
}

void Document::DeleteContent()
{
	m_Content.clear();
}

bool Document::isEmpty()
{
	return m_Content.empty();
}

const std::string& Document::GetContent() const
{
	return m_Content;
}
