#include <iostream>
#include <set>
#include <unordered_map>

using namespace std;

// TrieNode클래스를 사용하여 Trie의 각 노드를 표현
class TrieNode {

public:
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
    }

};

// Trie 클래스
class Trie {

    // Trie의 루트 노드에 대한 포인터인 Trie개인 멤버 변수
private:
    TrieNode* root; // 루트 노드

// 생성자새 인스턴스를 만들고 Trie를 초기화합
public:
    Trie() {
        root = new TrieNode();
    }

    // 문자열을 받아 Trie에 추가합니다. 
    // 루트 노드에서 시작하여 Trie 아래로 이동하여 단어의 각 문자에 필요한 새 노드를 만듭니다.
    void insert(string word) {
        TrieNode* curr = root; // 시작
        for (char c : word) {
            if (curr->children.find(c) == curr->children.end()) 
                curr->children[c] = new TrieNode(); // Trie에 없다면 새 노드 생성
            
            curr = curr->children[c]; // Trie에 이미 존재하는 경우 기존 노드로 이동
        }
        // 단어의 끝을 나타내는 isEndOfWord bool값
        curr->isEndOfWord = true;
    }

    // prefix(접두사)로 시작하는 단어가 Trie에 있는지 확인
    int startsWith(string prefix) {
        TrieNode* curr = root;
        for (char c : prefix) {
            if (curr->children.find(c) == curr->children.end()) 
                return curr->children.size();
            
            curr = curr->children[c];
        }
        return curr->children.size();
    }
};

int main() {

    Trie trie;
    int N;
    set<string> myV;
    string str;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> str;
        myV.insert(str); // set으로 중복 제거
        trie.insert(str);
    }

    int res = myV.size();

    for (auto &it : myV) 
        if (trie.startsWith(it) >= 1 ) res--;
    
    cout << res;

    return 0;
}
