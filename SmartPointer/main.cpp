#include "Document.h"

#include <iostream>
#include <memory>

namespace SimpleUsage { 
	namespace Raw {
		void Main() {
			Document* p = new Document{};
			p->SetTitle("Raw Pointer");
			p->AddContent("Using Raw Pointer");
			std::cout << *p << "\n";
			delete p;
		}
	}
	namespace SmartPointer {
		void Main() {
			std::unique_ptr<Document> p { new Document{} };
			p->SetTitle("Smart Pointer");
			p->AddContent("Using Smart Pointer");
			std::cout << *p << "\n";
		}
	}
}

namespace Sharing { 
	namespace Raw {
		class View 
		{
		public:
			void SetDocument(Document* pDoc)
			{
				m_pDocument = pDoc;
			}
			
			void Display() const 
			{
				std::cout << m_pDocument->GetTitle() 
						  << "->"
						  << m_pDocument->GetContent();
			}
			~View() 
			{
				delete m_pDocument;
			}
		private:
			Document* m_pDocument{};  
		};

		void Main()
		{
			View view{};
			Document* p = new Document{};
			view.SetDocument(p);
			p->SetTitle("Note");
			p->AddContent("Using Raw Pointer");
			view.Display();
			// delete p 这会导致View在析构函数中重复删除该指针引发内存错误

			// Document* p1 = new Document{};
			// view.SetDocument(p1); 
			// 上面的代码也会导致内存泄漏，因为指针p没有被View管理也没有被删除
		}
	}
	namespace SmartPointer {
		class View 
		{
		public:
			void SetDocument(std::shared_ptr<Document> pDoc)
			{
				m_pDocument = pDoc;
			}
			
			void Display() const 
			{
				std::cout << m_pDocument->GetTitle() 
						  << "->"
						  << m_pDocument->GetContent();
			}
		private:
			std::shared_ptr<Document> m_pDocument{nullptr};  
		};

		void Main()
		{
			View view{};
			std::shared_ptr<Document> p { new Document{} };
			view.SetDocument(p);
			p->SetTitle("Note");
			p->AddContent("Using Raw Pointer");
			view.Display();

			std::shared_ptr<Document> p1 { new Document{} };
			view.SetDocument(p1); 
		}
	}
}

namespace ReturnType {
	namespace Raw {
		Document* NewDocument(const std::string& title)
		{
			if(title.empty())
			{
				return nullptr;
			}
			return new Document{title};
		}

		void Main()
		{
			Document* p = NewDocument("Note");
			if(!p)
			{
				std::cout << "The Document creation failed.\n";
				return;
			}
			p->AddContent("This is something great.");
			std::cout << *p << "\n";
			delete p;
		}
	}
}
int main()
{
	// SimpleUsage::Raw::Main();
	// SimpleUsage::SmartPointer::Main();
	
	// Sharing::Raw::Main();
	// Sharing::SmartPointer::Main();

	ReturnType::Raw::Main();
	return 0;
}
