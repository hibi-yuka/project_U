        struct node_t{

            //�m�[�h���Ǘ�����f�[�^���̂���
            int number;
            char name[256];

            //�m�[�h���w���|�C���^,�\���̂������̍\���̂��w��
            struct node_t *left;
            struct node_t *right;

        }

        struct node_t *searchNode(struct node_t *root, int number){//�񕪒T���؂̒T���A�������Ƀ|�C���^�ō\���̕ϐ���n��
        //root = �T�����J�n����m�[�h�̃A�h���X number=�T������l

            struct node_t *node;//�\���̕ϐ��̃|�C���^
            node = root;//�����œn���ꂽ�A�h���X��node�ɓn��

            while(node){

                if(number < node -> number){�@//�T������number��node.number���r�A�T���l���m�[�g�̒l�����������ꍇ

                    node = node -> left;//�T������number�̒l���E���̒l���������������m�肵�Ă���̂ō����Ɣ�r����

                }else if( number > node -> number){//�T���l���m�[�h�̒l�����傫���ꍇ

                    node = node ->right;

                }else {
                    return node;
                }
            }

            return NULL;
        }

        struct node_t *mallocNode(int number, char *name){//�m�[�h�̍\���̂̃��������m�ۂ���

            struct node_t *add;

            //���I������(�v���O�����ɍ��킹���������v��)���m�ۂ���֐�
            add = (struct node_t*)malloc(sizeof(struct  node_t));
            if(add == NULL){

                return NULL;
            }

            add -> left = NULL;
            add -> right = NULL;
            add -> number = number;
            strcpy(add -> name, name);

            return add;
        }

        //�m�[�h��ǉ�����

        struct node_t *addNode(struct node_t *root, int number, char *name){
            
            struct node_t *node;//�ǉ�����node�̃|�C���^

            if(root == NULL){//�m�[�h������Ȃ��ꍇ�̓��[�g�m�[�h�Ƃ��Ēǉ�����

            root = mallocNode(number,name);//mallocNode����m�[�h�̃��������m�ۂ��A�f�[�^��ݒ�

            if(root = NULL){//�G���[����
                printf("malloc error\n");
                return NULL;
            }

            return root;//���[�g�m�[�h��Ԃ�

            }

            node = root;//���[�g���r����m�[�h�Ƃ���

            while(1){
                if(number < node -> number){//�T���l���ǉ������m�[�h�̒l���傫����

                    if(node -> left == NULL){//�ǉ������m�[�h�̍��������ꍇ

                        node->left = mallocNode(number, name);//�m�[�h��ǉ�

                        break;
                    }

                    node = node -> left;//�ǉ������m�[�h�����̔�r�m�[�h�Ƃ���

                }else if(number > node -> number){

                    if(node -> rihgt == NULL){

                        node->right = mallocNode(number, name);
                        break;
                    }

                }else{�@//�ǉ�����l�Ɣ�r�����m�[�h�̒l�������ꍇ

                    printf("%d already exist\n", number);
                    break;
                }
            }

            return root;
        }
    
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











