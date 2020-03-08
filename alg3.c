        struct node_t{

            //ノードが管理するデータそのもの
            int number;
            char name[256];

            //ノードを指すポインタ,構造体が自分の構造体を指す
            struct node_t *left;
            struct node_t *right;

        }

        struct node_t *searchNode(struct node_t *root, int number){//二分探索木の探索、仮引数にポインタで構造体変数を渡す
        //root = 探索を開始するノードのアドレス number=探索する値

            struct node_t *node;//構造体変数のポインタ
            node = root;//引数で渡されたアドレスをnodeに渡す

            while(node){

                if(number < node -> number){　//探索するnumberとnode.numberを比較、探索値がノートの値よりも小さい場合

                    node = node -> left;//探索するnumberの値が右側の値よりも小さい事が確定しているので左側と比較する

                }else if( number > node -> number){//探索値がノードの値よりも大きい場合

                    node = node ->right;

                }else {
                    return node;
                }
            }

            return NULL;
        }

        struct node_t *mallocNode(int number, char *name){//ノードの構造体のメモリを確保する

            struct node_t *add;

            //動的メモリ(プログラムに合わせたメモリ要領)を確保する関数
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

        //ノードを追加する

        struct node_t *addNode(struct node_t *root, int number, char *name){
            
            struct node_t *node;//追加するnodeのポインタ

            if(root == NULL){//ノードが一つもない場合はルートノードとして追加する

            root = mallocNode(number,name);//mallocNodeからノードのメモリを確保し、データを設定

            if(root = NULL){//エラー処理
                printf("malloc error\n");
                return NULL;
            }

            return root;//ルートノードを返す

            }

            node = root;//ルートを比較するノードとする

            while(1){
                if(number < node -> number){//探索値より追加したノードの値が大きい時

                    if(node -> left == NULL){//追加したノードの左側が内場合

                        node->left = mallocNode(number, name);//ノードを追加

                        break;
                    }

                    node = node -> left;//追加したノードを次の比較ノードとする

                }else if(number > node -> number){

                    if(node -> rihgt == NULL){

                        node->right = mallocNode(number, name);
                        break;
                    }

                }else{　//追加する値と比較したノードの値が同じ場合

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











