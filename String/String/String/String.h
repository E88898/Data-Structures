#ifndef STRING_H
#define STRING_H
#include <string>

class String
{
	friend std::ostream& operator<<(std::ostream& out, const String& object);
public:
	String();
	String(const char* string); 
	String(const String& other); // copy ctor
	String& operator=(const String& other); 
	~String();

	char& operator[](int index);
	char operator[](int index) const;

	String operator+(const String& other) const;
	String& operator+=(const String& other);

	bool operator==(const String& other);
	
	int getLength() const;

	struct stringException
	{
		std::string s;
	};
private:
	int _length;
	char* _data;

};

#endif