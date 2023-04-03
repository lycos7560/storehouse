#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> PreorderAnswer;
vector<int> PostorderAnswer;

// 노드를 만든다.
struct _Node
{
    int _Number; // 입력받은 순서를 저장
    pair<int, int> _data; // x, y 값을 저장
    struct _Node* _LeftNode;
    struct _Node* _RightNode;
    
    _Node(int x, int y, int n) {
        _Number = n; 
        _data = make_pair(x, y); 
        _LeftNode = NULL; // 기본 Null
        _RightNode = NULL; 

    };
};

// 트리를 생성하는 함수
void PushNode(_Node& p_ParentNode, _Node& p_Node)
{
    if (p_ParentNode._data.first > p_Node._data.first) {   
        if (p_ParentNode._LeftNode != NULL) PushNode(*p_ParentNode._LeftNode, p_Node);    
        else p_ParentNode._LeftNode = &p_Node;
    }
    else {
        if (p_ParentNode._RightNode != NULL) PushNode(*p_ParentNode._RightNode, p_Node);
        else p_ParentNode._RightNode = &p_Node;
    }
}

// 노드를 비교하고 정렬합니다. (Y값을 기준으로 오름차순으로 정렬합니다.)
bool Compare(_Node& p_A_Node, _Node& p_B_Node)
{
    return p_A_Node._data.second > p_B_Node._data.second;
}

// 전위 순회
void Preorder_Traverse(_Node* p_Node) {
    if (p_Node != NULL) {
        PreorderAnswer.push_back(p_Node->_Number);
        Preorder_Traverse(p_Node->_LeftNode);
        Preorder_Traverse(p_Node->_RightNode);
    }
}

// 후위 순회
void Postorder_Traverse(_Node* p_Node) {
    if (p_Node != NULL) {
        Postorder_Traverse(p_Node->_LeftNode);
        Postorder_Traverse(p_Node->_RightNode);
        PostorderAnswer.push_back(p_Node->_Number);
    }
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<_Node> _NodeVector; 
    for (int i = 0; i < nodeinfo.size(); i++) { // 정보를 받아서 노드를 생성하고 저장
        _Node node = { nodeinfo[i][0], nodeinfo[i][1], i + 1 };
        _NodeVector.push_back(node);
    }
  
    sort(_NodeVector.begin(), _NodeVector.end(), Compare); // Y값으로 정렬

    // Y값이 가장 높은 노드를 Root로 트리를 만든다. 
    for (int i = 1; i < _NodeVector.size(); i++) 
        PushNode(*_NodeVector.begin(), _NodeVector[i]); 

    Preorder_Traverse(&_NodeVector[0]);
    Postorder_Traverse(&_NodeVector[0]);

    vector<vector<int>> answer;

    answer.push_back(PreorderAnswer); // answer[0]
    answer.push_back(PostorderAnswer); // answer[1]

    return answer;
}