#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 256

/* 二分探索木のノードを表す構造体 */
struct node_t {
  int number;
  char name[MAX_NAME_LEN];
  struct node_t *left;
  struct node_t *right;
};


/* deleteTree:二分探索木のノード全てを削除する
   引数１ root : 根ノードのアドレス
   返却値 : なし */
void deleteTree(struct node_t *root){
  if(root == NULL){
    return;
  }

  if(root->left != NULL){
    deleteTree(root->left);
  }
  if(root->right != NULL){
    deleteTree(root->right);
  }

  printf("free:%d(%s)\n", root->number, root->name);
  free(root);

}

/* mallocNode:ノードの構造体のメモリを確保し、データを設定
   引数１ number : 追加する会員番号
   引数２ name : 追加する会員の名前
   返却値 : 追加したノードのアドレス */
struct node_t *mallocNode(int number, char *name){
  struct node_t *add;

  add = (struct node_t*)malloc(sizeof(struct node_t));
  if(add == NULL){ 
    return NULL;
  }

  add->left = NULL;
  add->right = NULL;
  add->number = number;
  strcpy(add->name, name);

  return add;
}

/* addNode:指定されたnumberとname持つノードを追加する
   引数１ root : 根ノードのアドレス
   引数２ number : 追加する会員番号
   引数３ name : 追加する会員の名前
   返却値 : 根ルートのアドレス */
struct node_t *addNode(struct node_t *root, int number, char *name){
  struct node_t *node;

  /* まだノードが一つもない場合 */
  if(root == NULL){
    /* 根ノードとしてノードを追加 */
    root = mallocNode(number, name);
    if(root == NULL){
      printf("malloc error\n");
      return NULL;
      }
      return root;
   }

   /* 根ノードから順に追加する場所を探索 */
   node = root;
   while(1) {
     if(number < node->number){
       /* 追加する値がノードの値よりも小さい場合 */

       if(node->left == NULL){
         /* そのノードの左の子が無い場合（もう辿るべきノードが無い場合）*/

         /* その左の子の位置にノードを追加 */
         node->left = mallocNode(number, name);

         /* 追加完了したので処理終了 */
         break;
       }

       /* 左の子がある場合は左の子を新たな注目ノードに設定 */
       node = node->left;

     } else if(number > node->number){
       /* 追加する値がノードの値よりも大きい場合 */

       if(node->right == NULL){
         /* そのノードの右の子が無い場合（もう辿るべきノードが無い場合）*/

         /* その右の子の位置にノードを追加 */
         node->right = mallocNode(number, name);

         /* 追加完了したので処理終了 */
         break;
       }

       /* 右の子がある場合は右の子を新たな注目ノードに設定 */
       node = node->right;
     } else {
       /* 追加する値とノードの値が同じ場合 */

       printf("%d already exist\n", number);
       break;
    }
   }
    
   return root;
}

/* searchNode:指定されたnumberを持つノードを探索する
   引数１ root : 探索を開始するノードのアドレス
   引数２ number : 探索する会員番号
   返却値 : number を持つノードのアドレス（存在しない場合は NULL）*/
struct node_t *searchNode(struct node_t *root, int number){
  struct node_t *node;
  
  node = root;

  /* 探索を行うループ（注目ノードがNULLになったら終了 */
  while(node){
    if(number < node->number){
      /* 探索値がノードの値よりも小さい場合 */

      /* 注目ノードを左の子ノードに設定 */
      node = node->left;
    } else if(number > node->number){
      /* 探索値がノードの値よりも大きい場合 */

      /* 注目ノードを右の子ノードに設定 */
      node = node->right;
    } else {
      /* 探索値 = ノードの値の場合 */
      return node;
    }
  }
  
  /* 探索値を持つノードが見つからなかった場合 */
  return NULL;
}

/* deleteNoChildeNode:指定された子の無いノードを削除する
   引数１ root : 木の根ノードのアドレス
   引数２ node : 削除するノードのアドレス
   引数３ parent：削除するノードの親ノードのアドレス
   返却値 : 根ノードのアドレス */
struct node_t *deleteNoChildNode(struct node_t *root, struct node_t *node, struct node_t *parent){

  if(parent != NULL){
    /* 親がいる場合（根ノード以外の場合）は
    削除対象ノードを指すポインタをNULLに設定 */
    if(parent->left ==  node){
       /* 削除対象ノードが親ノードから見て左の子の場合 */
        parent->left = NULL;
    } else {
      /* 削除対象ノードが親ノードから見て右の子の場合 */
      parent->right = NULL;
    }
    free(node);
  }  else {
    /* 削除対象ノードが根ノードの場合 */
    free(node);
      
    /* 根ノードを指すポインタをNULLに設定 */
    root = NULL;
  }
    
  return root;
}

/* deleteOneChildeNode:指定された子が一つのノードを削除する
   引数１ root : 木の根ノードのアドレス
   引数２ node : 削除するノードのアドレス
   引数３ child : 削除するノードの子ノードのアドレス
   返却値 : 根ノードのアドレス */
struct node_t *deleteOneChildNode(struct node_t *root, struct node_t *node, struct node_t * child){
   
  /* 削除対象ノードにその子ノードのデータとポインタをコピー */
  node->number = child->number;
  strcpy(node->name, child->name);
  node->left = child->left;
  node->right = child->right;
    
  /* コピー元のノードを削除 */
  free(child);
  
  return root;
}

/* deleteTwoChildeNode:指定された子が二つのノードを削除する
   引数１ root : 木の根ノードのアドレス
   引数２ node : 削除するノードのアドレス
   返却値 : 根ノードのアドレス */
struct node_t *deleteTwoChildNode(struct node_t *root, struct node_t *node){

  struct node_t *max;
  struct node_t *maxParent;
  
  /* 左の子から一番大きい値を持つノードを探索 */
  max = node->left;
  maxParent = node;
    
  while(max->right != NULL){
    maxParent = max;
    max = max->right;
  }
  printf("max number is %d\n", max->number);
    
  /* 最大ノードのデータのみ削除対象ノードにコピー */
  node->number = max->number;
  strcpy(node->name, max->name);
    
  /* 最大ノードを削除 */
  
  /* maxは最大ノードなので必ずmax->rightはNULLになる */
  if(max->left == NULL){
    /* 最大ノードに子がいない場合 */
    root = deleteNoChildNode(root, max, maxParent);      
    } else {
      /* 最大ノードに子供が一ついる場合 */
      root = deleteOneChildNode(root, max, max->left);
    }

    return root;
}



/* deleteNode:指定されたnumberを持つノードを削除する
   引数１ root : 木の根ノードのアドレス
   引数２ number : 削除する会員番号
   返却値 : 根ノードのアドレス */
struct node_t *deleteNode(struct node_t *root, int number){
  struct node_t *node;
  struct node_t *parent;

  if(root == NULL){
    return NULL;
  }

  /* 削除対象ノードを指すノードを探索 */
  node = root;
  parent = NULL;
  
  while(node !=  NULL){
    if(number < node->number){
      parent = node;
      node = node->left;
    } else if(number > node->number){
      parent = node;
      node = node->right;
    } else {
      break;
    }
  }
  
  /* 指定されたnumberを値として持つノードが存在しない場合は何もせず終了 */
  if(node == NULL){
    printf("%d を持つノードが存在しません\n", number);
    return root;
  }

  printf("Delete %d(%s) node\n", node->number, node->name);

  if(node->left == NULL && node->right == NULL){    
    /* 子がいないノードの削除 */
    root = deleteNoChildNode(root, node, parent);
  } else if((node->left != NULL && node->right == NULL) ||
    (node->right != NULL && node->left == NULL)){
    /* 子が一つしかない場合 */
    
    if(node->left != NULL){
      root = deleteOneChildNode(root, node, node->left);
    } else {
      root = deleteOneChildNode(root, node, node->right);
    }
  } else {
    /* 左の子と右の子両方がいるノードの削除 */
    root = deleteTwoChildNode(root, node);
  }
  
  return root;  
}

/* printTree:rootを根ノードとする二分探索木をの全ノードを表示する
   引数１ root : 木の根ノードのアドレス
   引数２ depth: 関数呼び出しの深さ
   返却値 : なし */
void printTree(struct node_t *root, int depth){
  int i;

  if(root == NULL){
    return ;
  }

  /* 右の子孫ノードを表示 */
  printTree(root->right, depth+1);
 
  /* 深さをスペースで表現 */ 
  for(i = 0; i < depth; i++){
    printf("  ");
  }

  /* ノードのデータを表示 */
  printf("+%3d(%s)\n", root->number, root->name);

  /* 左の子孫ノードを表示 */
  printTree(root->left, depth+1);

  depth++;
}

int main(void){
  struct node_t *root, *node;
  int input;
  int number;
  char name[MAX_NAME_LEN];
  int loop;

  /* まだ木がないのでrootをNULLにセット */
  root = NULL;

  /* 最初にてきとうにノードを追加しておく */
  root = addNode(root, 100, "100");
  root = addNode(root, 200, "200");
  root = addNode(root, 300, "300");
  root = addNode(root, 50, "50");
  root = addNode(root, 150, "150");
  root = addNode(root, 250, "250");
  root = addNode(root, 10, "1");
  root = addNode(root, 125, "125");
  root = addNode(root, 5, "5");
  root = addNode(root, 25, "25");
  root = addNode(root, 500, "500");
  root = addNode(root, 175, "175");

  loop = 1;
  while(loop){
    printf("処理を選択(1:add, 2:delete, 3:search, 4:exit)");
    scanf("%d", &input);

    switch(input){
    case 1:
      printf("会員番号(1 - 999):");
      scanf("%d", &number);
      if(number < 1 || number > 999){
        printf("値が範囲外です\n");
        continue;
      }

      printf("名前:");
      scanf("%s", name);

      root = addNode(root, number, name);
      break;
    case 2:
      printf("会員番号(1 - 999):");
      scanf("%d", &number);
      if(number < 1 || number > 999){
        printf("値が範囲外です\n");
        continue;
      }

      root = deleteNode(root, number);
      
      break;
    case 3:
      printf("会員番号(1 - 999):");
      scanf("%d", &number);
      if(number < 1 || number > 999){
        printf("値が範囲外です\n");
        continue;
      }
      
      node = searchNode(root, number);
      if(node == NULL){
        printf("number %d is not found\n", number);
      } else {
        printf("number %d : %s\n", number, node->name);
      }
      break;
    default:
      loop = 0;
      break;
    }
    printTree(root, 0);
  }

  deleteTree(root);   
  
  return 0;
}