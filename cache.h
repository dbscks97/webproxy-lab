/* 프록시 캐시를 저장할 링크드 리스트 구현 헤더 */

/*
    프록시에서 캐시를 저장하고 삭제할 구조체를 제공
    해당 구조체를 조작하는 함수 제공

    1. 캐시 구조체
        -> 링크드 리스트로 구현
            root, tail 포인터 필요 (LRU 구현을 위해), 총 size 필요
        -> 노드는 key : GET http://local../home.html HTTP/1.1), value(응답 데이터), 링크드 리스트를 위한 포인터 (next, prev)가 필요하다.

    3. 데이터 찾기
        1. key를 인자로 
        2. 데이터를 찾으면 1 반환 (buf 값을 인자로 받고 넣어주면 데이터는 거기에 값 채우기)
        3. 데이터를 못 찾으면 0 반환 

    2. 데이터 저장
        1. 최대 오브젝트 사이즈 이하만 저장
        2. 만약 넣으려는데 버퍼 사이즈 초과했다면?
           조회한지 가장 오래 된 노드를 찾아서 삭제하자
        

*/
#ifndef __CASHE_H__
#define __CASHE_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CACHE_SIZE 1049000
#define MAX_OBJECT_SIZE 102400

typedef struct node {
    char *key;         // 키
    char *value;       // 값
    struct node *prev; // 이전 노드
    struct node *next; // 다음 노드
} cache_node;

typedef struct cache{
    cache_node *root;     // 제잎 앞 노드를 가리키기
    cache_node *tail;     // 제일 뒤 노드를 가리키기 
    int size; // 현재 캐시 총 사이즈
} cache;

cache *new_cache();                                         // 캐시 초기화
int find_cache(cache *target_cache, char *key, char *buf); // 캐시에서 값 찾기
int insert_cache(cache *target_cache, char* key, char *value); // 캐시에 값 넣기
int init_cache(cache *target_cache);                           // 캐시 시작하기

#endif 
// end __CASH_H__