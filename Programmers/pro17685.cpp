#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// TrieNode클래스를 사용하여 Trie의 각 노드를 표현
class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    int num; // 연관된 단어의 개수를 저장
    TrieNode() {
        num = 0;
    }
};

// Trie 클래스
class Trie {

private: // Trie의 루트 노드에 대한 포인터인 Trie개인 멤버 변수
    TrieNode* root; // 루트 노드


public:
    Trie() { // 생성자새 인스턴스를 만들고 Trie를 초기화
        root = new TrieNode();
    }

    // 문자열을 받아 Trie에 추가합니다. 
    // 루트 노드에서 시작하여 Trie 아래로 이동하여 단어의 각 문자에 필요한 새 노드를 만듭니다.
    void insert(string word) {
        TrieNode* curr = root; // 시작
        for (char c : word) {
            if (curr->children.find(c) == curr->children.end()) {
                // Trie에 없다면 새 노드 생성
                curr->children[c] = new TrieNode();
            }

            // Trie에 이미 존재하는 경우 기존 노드로 이동
            curr = curr->children[c];
            curr->num++; // 연관된 단어의 개수 추가
        }
    }

    // 단어를 검색합니다.
    // 연관된 단어의 개수가 1이라면 글자수 반환
    int search(string word) {
        TrieNode* curr = root;
        int cnt = 0;
        for (char c : word) {
            curr = curr->children[c];
            cnt++;
            if (curr->num == 1) {
                // 연관된 단어의 개수가 1이라면 
                // 자동완성
                return cnt;
            }
        }
        return 9999; // 문제에서 나올 수 없는 경우 
    }

    // prefix(접두사)로 시작하는 단어가 Trie에 있는지 확인
    int startsWith(string prefix) {
        TrieNode* curr = root;
        for (char c : prefix) {
            if (curr->children.find(c) == curr->children.end()) {
                return false;
            }
            curr = curr->children[c];
        }
        return curr->children.size();
    }

};

int solution(vector<string> words) {
    int answer = 0;
    Trie trie;
    for (auto& it : words) {
        trie.insert(it);
    }

    for (auto& it : words) {
        if (trie.startsWith(it) >= 1) {
            // 접두사로 시작하는 단어가 있다면 
            // 단어 전체를 입력해야한다.
            answer += it.length();
            continue;
        }

        // 자동완성 확인
        answer += trie.search(it);
    }

    return answer;
}