

// author: idebtor@gmail.com
// return by reference - lecture note
// created: 2021-09-03 
/////////////////////////////////////////////////////////////////////////////
// Pointer도 어려운데 또 Reference를 공부하니 어렵죠?  
// 사실상 Pointer를 배우기 전에 Reference를 배웠으면 훨씬 더 쉬웠을 것 같아요. 
// 그래서, 예제를 하나 만들어 보았습니다. 
// 어떤 string이 하나 있는데, 그 중 lowercase중에 가장 큰 것을 찾아서 'Z'로 바꾸고 
// 싶다고 가정해 봅시다. 물론, 간단히 코딩할 수 있지만, return by reference를 
// 설명하기 위해, 가장 큰 character의 address(reference)를 찾아서 반환해주는 함수가
// 있다고 가정해봅시다. 그리고, 그 함수를 get_maxchar_reference()고 부릅시다. 
// 그러면, 이 함수의 prototype은 다음과 같을 것입니다. 
//
// char& get_maxchar_referehce(string& s)
//
// 앞에 있는 char & 가 바로 주소(reference)를 반환한다는 표시이고, 인자에 있는 
// string & 주소(reference)로 실제 메모리 주소를 인자로 넘겨준다는 표시입니다. 
// 여기까지 이해가 되었죠? 
// 이것을 호출해서 반환되는 것은 바로 string s 에서 가장 큰 소문자가 있는 
// 주소값(reference)일 것입니다.  바로 함수가 반환하는 그 주소가 가지고 있는 
// 메모리에 바로 'Z'를 아래와 같이 설정하면 끝나는 것입니다. 
//
// get_maxchar_reference( ..... ) = 'Z' 
//
// 이런 코드를 본 적이 있나요? 지금까지 대개 우리는 함수를 호출하면, 반환 받은 것을 
// 보통 저장하게 되죠? 그래서, 함수는 주로 assignment의  "right-hand side"에 
// 나타납니다. 
// x = get___function.... 이런 식으로 말입니다. 
// 그런데, 여기에서는 함수가 'left side'에 나타난다는 것입니다. 그래서, left-hand 
// size of the assignment라는 소리가 나오는 것입니다.  왜냐하면, reference 를 
// 반환받았다는 것은 무언가를 저장할 수 있는 주소값을 반환받았다는 것입니다. 
// 이제 다음 코드를 읽어보세요 

#include <iostream>
#include <string>
using namespace std;

// returns a reference to the largest lowercase char in the string.
char& get_maxchar_reference(string& s) 
{   // returns a reference to a char
    // find the largest lowercase char in the string s.
    char max = 'a'; 
    int idx = 0;
    int i = 0;
    for (char c: s) {
        if (c > max && c >= 'a' && c <= 'z') {
            max = c;
            idx = i;
        }
        i++;
    }
    return s.at(idx);  
}

int main()  
{
    string s = "Handong University";
    std::cout << s << endl;
    get_maxchar_reference(s) = 'Z';
    std::cout << s << endl;
    return 0;
}

