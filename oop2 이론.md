# Chapter 8 (Pointers)
### 포인터
왼쪽 : L-value(주소) , 오른쪽 : R-value(값)  
포인터 : 값을 다 계속 복사해서 주면 메모리 문제가 생기니깐 주소를 전달해줌 (메모리 추가 사용 X)  
\* : 주소를 값으로 
& : 값을 주소로
nullptr : 포인터 변수 초기화  
배열 : 동일한 data type의 연속적인 메모리 공간  
```cpp
int n[5];
display(n);
void display(int *ptr); 
void display(int ptr[]);
배열을 줄 때 배열의 크기도 주어야함
void display(const int* ptr , const size_t size);
```

### const
const int* ptr : 값을 바꿀 수 없음  
int* const ptr : 주소를 바꿀 수 없음
```cpp
int arr; 
arr == arr[0];
```
# Chapter 9 (Classes : A Deeper Look)

### 헤더파일이 중복되는 것 방지
```cpp
#ifndef TIME_H
#define TIME_H

#endif
```
### ostringstream

```cpp  
ostringstream output;
return output.str()
```
 
### 생성자 소멸자
생성자 순서 : 생성자는 있는 그대로  
소멸자 순서 : 소멸자는 그냥 -> static -> 전역 순서  
소멸자는 동작할당한 메모리를 해제할 때 쓴다.  

### 객체의 주소를 밖으로 주면
객체지향에서의 캡슐화가 깨진다. 
크래킹에서 쓴다.

![image](https://user-images.githubusercontent.com/86973831/145575225-41ff53fd-5625-4f77-94dc-5d5a870fb06b.png)





### friend  
멤버변수에 접근할 수 있도록 도와줌  

### this pointer
this : 객체를 가리키는 주소 포인터  
\*this : this pointer가 가리키는 객체  
객체의 주소를 넘기는 방법 

```cpp
Time& setHour(int s){

    return *this;
}
//클래스를 주고 받을 땐 Time&를 
```
### static

### 작동과정
![image](https://user-images.githubusercontent.com/86973831/145575152-6802abf5-c8dd-49f7-81f4-18e4190cd9fb.png)  
cpp + h -> compiler -> obj -> linker -> exe  

  

# Chapter 10 (Operator Overloading)
### cin, cout 
```cpp
friend ostream& opeartor<<(ostream&, const A&);
friend istream& opeartor>>(istream& A&);

ostream& operator<<(ostream& os, const A& a){
    return os;
}
istream& opeartor>>(istream& is, A& a){
    return is;
}
```

### a++, ++a 
```cpp
Date& operator++();
Date operator++(int);

Date& operator++(){//++a
    this->x++;
    return *this;
}
Date opeartor++(int){//a++
    A tmp = *this;
    this->x++;
    return tmp;
}
``` 

### 복사  생성자  
```cpp
class A{
    int* ptr;
    size_t s;
};

A a = b;
```
a가 b의 힙 주소를 참조한다는 뜻이다
이렇게 할당하게 되면 b의 주소가 사라지면 a가 길을 잃게된다(Dangling point 문제)  
그래서 a는 주소를 따로 할당하고 값만 b에서 가져와야한다

### explicit
생성자 앞에 explicit를 쓰면 자동형 변환을 할 수 없어 에러를 띄운다 (안쓰면 에러 없음)  

# Chapter 11 (Inheritance) 
### 상속
상속 : 부모로 갈수록 추상적이고, 자식으로 갈수록 구체적이다  
상속은 쓸데없는 것도 다 가져온다  
Copy and paste는 가져오고 싶은 것만 가져올 수 있다  
부모의 private는 접근할 수 없다  
직계 부모의 protected는 접근할 수 있다

### Upriding  
같은 이름의 멤버함수 일때 자식의 것이 우선 순위  
자식에 없으면 올라가서 찾음   
 
# Chapter 12 (Polymorphism)
### virtual  
부모객체에 바인딩 된 자식객체의 클래스의 함수를 불러올 수 있게 한다  
바인딩 : 메모리에 올리는 행위(동적 바인딩, 정적 바인딩)
부모에 virtual로 선언된 함수는 자식에서 무조건 구현해야 한다

```cpp
virtual double earnings() const = 0;
```
순수가상함수  

### class size  
![image](https://user-images.githubusercontent.com/86973831/145681714-d35c4097-36a7-41e5-ae34-887fa7babd69.png)  
virtual function이 있으면 vTable이 만들어지는데 이 size가 4byte이기 때문에  
virtual function이 있는 클래스는 4바이트가 더 많다  

### dynamic_cast
dynamic_cast를 쓰면 자식객체에 부모객체를 바인딩할 수 있다
```cpp
parent *p;
Child* c = dynamic_cast<child*>(p);
```  
바인딩에 오류가 있으면 nullPtr을 반환한다

### 다중상속  
상속받은 클래스에 각각 같은 이름의 함수가 있을 경우 모호성의 띄기 때문에 어느 클래스인지 명확히 정의

# Chapter 13 (Stream input/output)
### CPU, IO장치, RAM  
IO장치는 느린데 CPU, RAM은 빠르다  
프로그램과 IO장치에는 stream buffer가 존재한다  

### 입출력  
cin.get, cin.put : 한글자씩 읽고 씀  
cin.read, cin.write : 한줄씩 읽고 씀  
eof : 항상 입력 끝에 존재함  
cin.width(n) : n개만큼 입력받아음  
cout.width(n) : n개의 공간에 출력함  

### iomanip
hex, oct, dec, setbase(n) : 진법 변환  
showbase : 진법을 보여준다  
fixed : 소수점 고정  
precision(n) : 숫자를 n개 보여준다  
showpoint : 소수점 남은자리의 0을 보여준다 ex) 9.99000->9.99000 안쓰면 9.99000->9.99  
setw(n) : n개의 자리를 잡고 입력  
left : 왼쪽 정렬 / right : 오른쪽 정렬  
showpos : 부호를 앞으로 넘겨준다
internal : 단위를 앞으로 빼준다
cout.fill() : setw의 빈공간을 원하는 문자로 채워준다  
scientific : 큰 숫자 표현  
uppercase : 대문자로 표현
boolalpha : 1/0을 true/false 로 나타냄  
cout.flags() : flag상태를 숫자로 나타내줌  

# Chapter 14 (File processing)  
파일은 HDD에 있음  
APP이 OS에게 HDD에 파일을 만들어 달라고 요청한다  
그 여부를 OS가 APP에 알려줌  


### 입출력에 스트림을 쓰는 이유  
1) 입출력 장치와 메모리간의 속도 차이 극복  
2) 프로그램과 다양한 입출력간의 분리  
![image](https://user-images.githubusercontent.com/86973831/145683567-8c8c2270-310d-44e1-a440-8f810dc6290f.png)  
![image](https://user-images.githubusercontent.com/86973831/145683634-51df088b-ea22-4686-8a0a-81b3fe69c181.png)  

### 파일쓰기 모드
ios::app : 파일 내용 보장 , 파일 포인터 보장  
ios::ate : 파일 내용 삭제 , 파일 포인터 보장

### reinterpret_cast  
```cpp
ostream os;
istream is;
os.write(reinterpret_cast<const char*>(&객체),sizeof(클래스));
os.seekp((인덱스-1)*sizeof(클래스));
is.seekg((인덱스-1)*sizeof(클래스));
is.read(reinterpret_cast<char*>(&객체),sizeof(클래스));
```

### 데이터 지우기
Blank class를 만들어 대입한다  
인덱스 번호를 0으로 바꾼다  

# Chapter 15 (STL container, iterator)  
### 시퀀스 컨테이너  
: vector, deque, list, forward_list  
데이터를 선형으로 저장  
순방향 반복자가 하나이상 있어야한다  
특정 위치 데이터를 가져올 수 있어야함

### 연관 컨테이너  
: set, multiset, map, multimap  
key와 value의 쌍으로 이루어져 있음  
데이터를 일정 규칙에 따라 조직화하여 저장  

### 컨테이너 어뎁터 
: stack, queue, priority_queue  
스퀀스나 연관 컨테이너의 변형  
반복자를 지원하지 않아 STL알고리즘에서는 사용하지 못함  

### STL
알고리즘에 중점을 둔다
#### 반복자
1. 참조연산자  
2. 대입연산, 비교연산  
3. 증가 연산

# Chapter 17 (Exception Handling)  
![image](https://user-images.githubusercontent.com/86973831/145685651-736db552-0097-4498-b9e1-86702904cc36.png)  
### new
```cpp
#include <new>

try{
    int *a = new int[1000000];
}
catch(bad_alloc& memoryAllocationException){
    cout << memoryAllocationException.what();
}
```
동적할당 오류 잡는 법  

# 마지막 정리
#ifndef, 컴파일순서, 생성자/소멸자, 캡슐화 깨는 행위, const, friend 개념  
연산자 오버로딩, 복사생성자, dangling point, 상속 권한, 상속 생성자 소멸자 순서  
다형성 구현, 다형성 함수 구현, cast함수  
입출력 구현  
파일 입출력, 파일 경로  
template, 컨테이너 사용법  
try-catch문  
