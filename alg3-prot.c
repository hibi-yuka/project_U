#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 256

/* �񕪒T���؂̃m�[�h��\���\���� */
struct node_t {
  int number;
  char name[MAX_NAME_LEN];
  struct node_t *left;
  struct node_t *right;
};


/* deleteTree:�񕪒T���؂̃m�[�h�S�Ă��폜����
   �����P root : ���m�[�h�̃A�h���X
   �ԋp�l : �Ȃ� */
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

/* mallocNode:�m�[�h�̍\���̂̃��������m�ۂ��A�f�[�^��ݒ�
   �����P number : �ǉ��������ԍ�
   �����Q name : �ǉ��������̖��O
   �ԋp�l : �ǉ������m�[�h�̃A�h���X */
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

/* addNode:�w�肳�ꂽnumber��name���m�[�h��ǉ�����
   �����P root : ���m�[�h�̃A�h���X
   �����Q number : �ǉ��������ԍ�
   �����R name : �ǉ��������̖��O
   �ԋp�l : �����[�g�̃A�h���X */
struct node_t *addNode(struct node_t *root, int number, char *name){
  struct node_t *node;

  /* �܂��m�[�h������Ȃ��ꍇ */
  if(root == NULL){
    /* ���m�[�h�Ƃ��ăm�[�h��ǉ� */
    root = mallocNode(number, name);
    if(root == NULL){
      printf("malloc error\n");
      return NULL;
      }
      return root;
   }

   /* ���m�[�h���珇�ɒǉ�����ꏊ��T�� */
   node = root;
   while(1) {
     if(number < node->number){
       /* �ǉ�����l���m�[�h�̒l�����������ꍇ */

       if(node->left == NULL){
         /* ���̃m�[�h�̍��̎q�������ꍇ�i�����H��ׂ��m�[�h�������ꍇ�j*/

         /* ���̍��̎q�̈ʒu�Ƀm�[�h��ǉ� */
         node->left = mallocNode(number, name);

         /* �ǉ����������̂ŏ����I�� */
         break;
       }

       /* ���̎q������ꍇ�͍��̎q��V���Ȓ��ڃm�[�h�ɐݒ� */
       node = node->left;

     } else if(number > node->number){
       /* �ǉ�����l���m�[�h�̒l�����傫���ꍇ */

       if(node->right == NULL){
         /* ���̃m�[�h�̉E�̎q�������ꍇ�i�����H��ׂ��m�[�h�������ꍇ�j*/

         /* ���̉E�̎q�̈ʒu�Ƀm�[�h��ǉ� */
         node->right = mallocNode(number, name);

         /* �ǉ����������̂ŏ����I�� */
         break;
       }

       /* �E�̎q������ꍇ�͉E�̎q��V���Ȓ��ڃm�[�h�ɐݒ� */
       node = node->right;
     } else {
       /* �ǉ�����l�ƃm�[�h�̒l�������ꍇ */

       printf("%d already exist\n", number);
       break;
    }
   }
    
   return root;
}

/* searchNode:�w�肳�ꂽnumber�����m�[�h��T������
   �����P root : �T�����J�n����m�[�h�̃A�h���X
   �����Q number : �T���������ԍ�
   �ԋp�l : number �����m�[�h�̃A�h���X�i���݂��Ȃ��ꍇ�� NULL�j*/
struct node_t *searchNode(struct node_t *root, int number){
  struct node_t *node;
  
  node = root;

  /* �T�����s�����[�v�i���ڃm�[�h��NULL�ɂȂ�����I�� */
  while(node){
    if(number < node->number){
      /* �T���l���m�[�h�̒l�����������ꍇ */

      /* ���ڃm�[�h�����̎q�m�[�h�ɐݒ� */
      node = node->left;
    } else if(number > node->number){
      /* �T���l���m�[�h�̒l�����傫���ꍇ */

      /* ���ڃm�[�h���E�̎q�m�[�h�ɐݒ� */
      node = node->right;
    } else {
      /* �T���l = �m�[�h�̒l�̏ꍇ */
      return node;
    }
  }
  
  /* �T���l�����m�[�h��������Ȃ������ꍇ */
  return NULL;
}

/* deleteNoChildeNode:�w�肳�ꂽ�q�̖����m�[�h���폜����
   �����P root : �؂̍��m�[�h�̃A�h���X
   �����Q node : �폜����m�[�h�̃A�h���X
   �����R parent�F�폜����m�[�h�̐e�m�[�h�̃A�h���X
   �ԋp�l : ���m�[�h�̃A�h���X */
struct node_t *deleteNoChildNode(struct node_t *root, struct node_t *node, struct node_t *parent){

  if(parent != NULL){
    /* �e������ꍇ�i���m�[�h�ȊO�̏ꍇ�j��
    �폜�Ώۃm�[�h���w���|�C���^��NULL�ɐݒ� */
    if(parent->left ==  node){
       /* �폜�Ώۃm�[�h���e�m�[�h���猩�č��̎q�̏ꍇ */
        parent->left = NULL;
    } else {
      /* �폜�Ώۃm�[�h���e�m�[�h���猩�ĉE�̎q�̏ꍇ */
      parent->right = NULL;
    }
    free(node);
  }  else {
    /* �폜�Ώۃm�[�h�����m�[�h�̏ꍇ */
    free(node);
      
    /* ���m�[�h���w���|�C���^��NULL�ɐݒ� */
    root = NULL;
  }
    
  return root;
}

/* deleteOneChildeNode:�w�肳�ꂽ�q����̃m�[�h���폜����
   �����P root : �؂̍��m�[�h�̃A�h���X
   �����Q node : �폜����m�[�h�̃A�h���X
   �����R child : �폜����m�[�h�̎q�m�[�h�̃A�h���X
   �ԋp�l : ���m�[�h�̃A�h���X */
struct node_t *deleteOneChildNode(struct node_t *root, struct node_t *node, struct node_t * child){
   
  /* �폜�Ώۃm�[�h�ɂ��̎q�m�[�h�̃f�[�^�ƃ|�C���^���R�s�[ */
  node->number = child->number;
  strcpy(node->name, child->name);
  node->left = child->left;
  node->right = child->right;
    
  /* �R�s�[���̃m�[�h���폜 */
  free(child);
  
  return root;
}

/* deleteTwoChildeNode:�w�肳�ꂽ�q����̃m�[�h���폜����
   �����P root : �؂̍��m�[�h�̃A�h���X
   �����Q node : �폜����m�[�h�̃A�h���X
   �ԋp�l : ���m�[�h�̃A�h���X */
struct node_t *deleteTwoChildNode(struct node_t *root, struct node_t *node){

  struct node_t *max;
  struct node_t *maxParent;
  
  /* ���̎q�����ԑ傫���l�����m�[�h��T�� */
  max = node->left;
  maxParent = node;
    
  while(max->right != NULL){
    maxParent = max;
    max = max->right;
  }
  printf("max number is %d\n", max->number);
    
  /* �ő�m�[�h�̃f�[�^�̂ݍ폜�Ώۃm�[�h�ɃR�s�[ */
  node->number = max->number;
  strcpy(node->name, max->name);
    
  /* �ő�m�[�h���폜 */
  
  /* max�͍ő�m�[�h�Ȃ̂ŕK��max->right��NULL�ɂȂ� */
  if(max->left == NULL){
    /* �ő�m�[�h�Ɏq�����Ȃ��ꍇ */
    root = deleteNoChildNode(root, max, maxParent);      
    } else {
      /* �ő�m�[�h�Ɏq���������ꍇ */
      root = deleteOneChildNode(root, max, max->left);
    }

    return root;
}



/* deleteNode:�w�肳�ꂽnumber�����m�[�h���폜����
   �����P root : �؂̍��m�[�h�̃A�h���X
   �����Q number : �폜�������ԍ�
   �ԋp�l : ���m�[�h�̃A�h���X */
struct node_t *deleteNode(struct node_t *root, int number){
  struct node_t *node;
  struct node_t *parent;

  if(root == NULL){
    return NULL;
  }

  /* �폜�Ώۃm�[�h���w���m�[�h��T�� */
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
  
  /* �w�肳�ꂽnumber��l�Ƃ��Ď��m�[�h�����݂��Ȃ��ꍇ�͉��������I�� */
  if(node == NULL){
    printf("%d �����m�[�h�����݂��܂���\n", number);
    return root;
  }

  printf("Delete %d(%s) node\n", node->number, node->name);

  if(node->left == NULL && node->right == NULL){    
    /* �q�����Ȃ��m�[�h�̍폜 */
    root = deleteNoChildNode(root, node, parent);
  } else if((node->left != NULL && node->right == NULL) ||
    (node->right != NULL && node->left == NULL)){
    /* �q��������Ȃ��ꍇ */
    
    if(node->left != NULL){
      root = deleteOneChildNode(root, node, node->left);
    } else {
      root = deleteOneChildNode(root, node, node->right);
    }
  } else {
    /* ���̎q�ƉE�̎q����������m�[�h�̍폜 */
    root = deleteTwoChildNode(root, node);
  }
  
  return root;  
}

/* printTree:root�����m�[�h�Ƃ���񕪒T���؂��̑S�m�[�h��\������
   �����P root : �؂̍��m�[�h�̃A�h���X
   �����Q depth: �֐��Ăяo���̐[��
   �ԋp�l : �Ȃ� */
void printTree(struct node_t *root, int depth){
  int i;

  if(root == NULL){
    return ;
  }

  /* �E�̎q���m�[�h��\�� */
  printTree(root->right, depth+1);
 
  /* �[�����X�y�[�X�ŕ\�� */ 
  for(i = 0; i < depth; i++){
    printf("  ");
  }

  /* �m�[�h�̃f�[�^��\�� */
  printf("+%3d(%s)\n", root->number, root->name);

  /* ���̎q���m�[�h��\�� */
  printTree(root->left, depth+1);

  depth++;
}

int main(void){
  struct node_t *root, *node;
  int input;
  int number;
  char name[MAX_NAME_LEN];
  int loop;

  /* �܂��؂��Ȃ��̂�root��NULL�ɃZ�b�g */
  root = NULL;

  /* �ŏ��ɂĂ��Ƃ��Ƀm�[�h��ǉ����Ă��� */
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
    printf("������I��(1:add, 2:delete, 3:search, 4:exit)");
    scanf("%d", &input);

    switch(input){
    case 1:
      printf("����ԍ�(1 - 999):");
      scanf("%d", &number);
      if(number < 1 || number > 999){
        printf("�l���͈͊O�ł�\n");
        continue;
      }

      printf("���O:");
      scanf("%s", name);

      root = addNode(root, number, name);
      break;
    case 2:
      printf("����ԍ�(1 - 999):");
      scanf("%d", &number);
      if(number < 1 || number > 999){
        printf("�l���͈͊O�ł�\n");
        continue;
      }

      root = deleteNode(root, number);
      
      break;
    case 3:
      printf("����ԍ�(1 - 999):");
      scanf("%d", &number);
      if(number < 1 || number > 999){
        printf("�l���͈͊O�ł�\n");
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