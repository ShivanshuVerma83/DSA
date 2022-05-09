#include <iostream>
#include <string>


using namespace std;


class Book{
private:
	string author; 
	string title;
	int price;
	string publisher;
	int stock;
public:
	
	Book(){}
	
	Book(string author,string title,double price,string publisher,int stock){
		this->author=author;
		this->title=title;
		this->price=price;
		this->publisher=publisher;
		this->stock=stock;
	}
	
	string getAuthor() {
		return author;
	}
	void setAuthor(string author) {
		this->author = author;
	}
	string getTitle() {
		return title;
	}
	void setTitle(string title) {
		this->title = title;
	}
	float getPrice() {
		return price;
	}
	void setPrice(int price) {
		this->price = price;
	}



	string getPublisher() {
		return publisher;
	}
	void setPublisher(string publisher) {
		this->publisher = publisher;
	}
	int getStock() {
		return stock;
	}
	void setStock(int quantity) {
		this->stock = quantity;
	}


	bool decreaseQuantityStock(int quantity) {
		if(this->stock-quantity>=0) {
			this->stock-=quantity;
			return true;
		}else {
			return false;
		}
	}
};
int main (){
	
	int totalNumberBooks=0;
	Book books[100];
	int ch=-1;


	string author; 
	string title;
	double price;
	string publisher;
	int stock;


	while(ch!=5){
		cout<<"1.  new book daalo\n";
		cout<<"2. Edit a book price\n";
		cout<<"3.  book khareed lo\n";
		cout<<"4. Display \n";
		cout<<"5. chal nikal ab\n";
		cout<<"Your choice: ";
		cin>>ch;
		cin.ignore();
		if(ch==1){
			cout<<" author of book: ";
			getline(cin,author);
			cout<<" title of book: ";
			getline(cin,title);
			cout<<" price of book: ";
			cin>>price;
			cin.ignore();
			cout<<"publisher of book: ";
			getline(cin,publisher);
			cout<<" number of books: ";
			cin>>stock;
			Book newBook(author,title,price,publisher,stock);
			books[totalNumberBooks]=newBook;
			totalNumberBooks++;
			cout<<"\nA new book has been added.\n\n";
            }else{
			cout<<"\nchal nikal ab\n\n";
		}
	}
	
	return 0;
}

