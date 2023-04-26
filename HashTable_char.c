#include <stdio.h>
#include <stdlib.h>
#define MAX_NODE 13

void mstrcpy(char dst[], const char src[]) {
    int c = 0;
    while ((dst[c] = src[c]) != 0) ++c;
}

typedef unsigned long long LL;

// 해시 인덱스 계산
int str_to_hash(const char* str) {
    int ret = 0;
    for (int i = 0; i < 3; i++) {
        ret <<= 5;
        ret += ((str[i] - 'a') + 1);
    }
    return ret;
}

// 나머지 글자 숫자로 변경
LL str_to_id(const char* str) {
    LL ret = 0;
    for (int i = 3; str[i] != 0; i++) {
        ret <<= 5;
        ret += ((str[i] - 'a') + 1);
    }
    return ret;
}

struct Node {
    char str[15];
    LL id;
    int hash;
    struct Node* prev;
    struct Node* next;
};

// 노드 배열 준비
int node_arr_idx = 0;
struct Node node_arr[MAX_NODE];

// 노드 생성
struct Node* get_node(struct onst char* str) {
    struct Node* node = &node_arr[node_arr_idx++];
    mstrcpy(node->str, str);
    return node;
}

// 해시 배열 준비
struct Node* node_hash[MAX_HASH];

void add_to_hash(struct Node* node) {
    node->next = node_hash[node->hash];
    if (node->next != 0) {
        node->next->prev = node;
    }

    node_hash[node->hash] = node;
    node->prev = 0;
}

// 해시에서 제거
void del_to_hash(struct Node* node) {
    if (node->next != 0) {
        node->next->prev = node->prev;
    }
    if (node->prev != 0) {
        node->prev->next = node->next;
    }
    if (node->prev == 0) {
        node_hash[node->hash] = node->next;
    }
}

// 해시에서 검색
struct Node* find_node(const char* str) {
    int hash = str_to_hash(str);
    LL id = str_to_id(str);

    struct Node* cur = node_hash[hash];
    for (; cur != 0; cur = cur->next) {
        if (cur->id == id) {
            return cur;
        }
    }
    return 0;
}

// 해시 정보 출력
void print_hash_info(int hash) {
    struct Node* node = node_hash[hash];
    struct Node* cur = node_hash[hash];
    for (; cur != 0; cur = cur->next) {
        printf("%s ->", cur->str);
    }
    printf("Empty\n");
}

int main() {

    // 노드 생성
    struct Node* n1 = get_node("hello");
    n1->id = str_to_id(n1->str);
    n1->hash = str_to_hash(n1->str);

    // 노드 추가
    add_to_hash(n1);
    print_hash_info(n1->hash);

    // 노드 생성
    struct Node* n2 = get_node("helkkk");
    n2->id = str_to_id(n2->str);
    n2->hash = str_to_hash(n2->str);

    // 노드 추가
    add_to_hash(n2);
    print_hash_info(n2->hash);

    // 노드 검색
    struct Node* n3 = find_node("helkkk");

    // 노드 삭제
    del_to_hash(n3);
    print_hash_info(n3->hash);

    // 노드 검색
    struct Node* n4 = find_node("hello");
    del_to_hash(n4);

    // 노드 삭제
    del_to_hash(n3);
    print_hash_info(n3->hash);

    return 0;
}
