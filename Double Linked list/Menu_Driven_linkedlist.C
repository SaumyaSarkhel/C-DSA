#include <stdio.h>
#include <stdlib.h> //Double linked list

struct Node{
    struct Node *prev, *next;
    int data;
};
struct Node *head = NULL;

void insert_Beg();
void insert_End();
void Insert_After_Position();
void Insert_Before_Position();
void Insert_After_Value();
void delete_Begining();
void Delete_From_End();
void Delete_Any_Position();
void count_Nodes();
void display();
void reverce();
void Findmax();
void Findmin();
void LinearSearch();
void selection_sort();


int main(){
    int choice;
    while (1){
        printf("\n1. Insert at beginning \n2. Insert at end \n3. Insert after any position \n4. Insert before any position \n5. Insert after any value \n6. Delete from beginning \n7. Delete from end\n8. Delete from any position \n9. Reverce\n10. Display\n11. Count\n12. Find Max\n13. Find min\n14. Linear search\n15. Selection sort\n16. exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice){
        case 1: insert_Beg();
                break;
        case 2: insert_End();
                break;
        case 3: Insert_After_Position();
                break;
        case 4: Insert_Before_Position();
                break;
        case 5: Insert_After_Value();
                break;
        case 6: delete_Begining();
                break;
        case 7: Delete_From_End();
                break;
        case 8: Delete_Any_Position();
                break;
        case 9: reverce();
                break;
        case 10: display();
                break;
        case 11: count_Nodes();
                break;
        case 12: Findmax();
                break;
        case 13: Findmin();
                break;
        case 14: LinearSearch();
                break;
        case 15: selection_sort();
                display();
                break;
        case 16: exit(0);
        default:
            printf("Invalid choice, enter right choice.\n");
        }
    }
}


void insert_Beg(){
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter your data: ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    temp->prev = NULL;
    if (head == NULL){
        head = temp;
    }
    else{
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void insert_End(){
    struct Node *temp, *p=head;
    temp = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter your data: ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    temp->prev = NULL;
    if (head == NULL){
        head=temp;
    }
    else{
        while (p->next != NULL){
            p = p->next;
        }
        p->next = temp;
        temp->prev = p;
    }
}

void Insert_After_Position(){
    int pos;
    struct Node *temp, *p;
    temp = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter your data: ");
    scanf("%d", &temp->data);
    printf("Enter your position: ");
    scanf("%d", &pos);
    temp->next = NULL;
    temp->prev = NULL;
    if (head == NULL){
        head = temp;
    }
    else{
        p=head;
        int i=1;
        if(pos<=0){
            printf("Invalid Position\n");
            return;
        }
        while (i<pos && p->next!=NULL){
            p = p->next;
            i++;
        }
        if (i==pos && p->next!=NULL){
            temp->next=p->next;
            temp->prev=p;
            p->next=temp;
        }
        else if (i==pos && p->next==NULL){
            p->next=temp;
            temp->prev = p;
        }
        else if (i!=pos && p->next==NULL){
            printf("Invalid Position\n");
        }
    }
}

void Insert_Before_Position(){
    int pos;
    int i = 1;
    struct Node *temp, *p=head;
    temp = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter your data: ");
    scanf("%d", &temp->data);
    printf("Enter your position: ");
    scanf("%d", &pos);
    pos = pos - 1;
    temp->next = NULL;
    temp->prev = NULL;
    if (head == NULL){
        head = temp;
    }
    else{
        if(pos<=0){
            printf("Invalid Position\n");
        }
        else if (pos==0){
            temp->next=head;
            head=temp;
        }
        else{
            while (i<pos && p->next!=NULL){
                p = p->next;
                i++;
            }
            if (i==pos && p->next!=NULL){
                temp->next = p->next;
                temp->prev = p;
                p->next=temp;
            }
            else if (i==pos && p->next==NULL){
                p->next=temp;
                temp->prev=p;
            }
            else if (i!=pos && p->next==NULL){
                printf("Invalid Position\n");
            }
        }
    }
}

void Insert_After_Value(){
    int value;
    struct Node *temp, *p=head;
    temp = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter your data: ");
    scanf("%d", &temp->data);
    printf("Enter your value: ");
    scanf("%d", &value);

    temp->next = NULL;
    temp->prev = NULL;
    if (head == NULL){
        head = temp;
    }
    else{
        while (p->data!=value && p->next!=NULL){
            p = p->next;
        }
        if (p->data==value && p->next!=NULL){
            temp->next = p->next;
            temp->prev = p;
            p->next = temp;
        }
        else if (p->data==value && p->next==NULL){
            p->next = temp;
            temp->prev = p;
        }
        else if (p->data!=value && p->next==NULL){
            printf("Value not exist.\n");
        }
    }
}

void delete_Begining(){
    struct Node *p;
    if(head==NULL){
      printf("Empty list\n");
    }
    else{
      p = head;
      head = head->next;
      head->prev = NULL;
      p->next=NULL;
      printf("Deleted data is : %d\n",p->data);
      free(p);
    }
}

void Delete_From_End(){
    struct Node *p=head, *q=head;
    if(head==NULL){
      printf("Empty list\n");
    }
    else{
      while(p->next!=NULL){
          q=p;
          p=p->next;
      }
        q->next=NULL;
        p->prev=NULL;
        printf("Deleted data is : %d\n",p->data);
    }
}

void Delete_Any_Position(){
    int pos, i=1;
    printf("Enter Your position: ");
    scanf("%d",&pos);
    struct Node *p=head, *q=head;
    if(head==NULL){
      printf("Empty list\n");
    }
    else{
        if(p->prev==NULL && p->next==NULL){
            head=p->next;
            head->prev=NULL;
            p->next=NULL;
            printf("Deleted Data is :%d\n",p->data);
            free(p);
        }
        else{
            if(pos<=0){
            printf("Invalid Position\n");
            return;
            }
            else if(pos==1){
            head = p->next;
            head->prev = NULL;
            p->next=NULL;
            printf("Deleted data is : %d\n",p->data);
            }
            else{
                while(p->next!=NULL && i<pos){
                    q=p;
                    p=p->next;
                    i++;
                }
                if(i==pos && p->next!=NULL){
                    q->next=p->next;
                    p->next->prev=q;
                    printf("Deleted Data is : %d\n",p->data);
                }
                else if(i==pos && p->next==NULL){
                    printf("Deleted data is : %d\n",p->data);
                }
                else if(i!=pos && p->next==NULL){
                    printf("Invalid position\n");
                }
            }
        }
    }
}

void count_Nodes(){
    struct Node *ptr=head;
    int count=0;
    while(ptr!=NULL){
        ptr=ptr->next;
        count++;
    }
    printf("The total number of Node is : %d\n",count);
}

void reverce(){
    struct Node *p, *q;
    for(p=head; p->next!=NULL; p=p->next);
    printf("NULL");
    for(q=p; q!=NULL; q=q->prev){
        printf(" <-> %d", q->data);
    }
    printf(" <-> NULL\n");
}

void display(){
    struct Node *ptr = head;
    printf("NULL");
    while (ptr != NULL)
    {
        printf(" <-> %d", ptr->data);
        ptr = ptr->next;
    }
    printf(" <-> NULL\n");
}

void Findmax(){
    struct Node *p;
    int max;
    if(head==NULL){
        printf("Empty list");
    }
    else{
        p=head;
        max=p->data;
        for(p=head; p!=NULL; p=p->next){
            if(max<p->data){
                max=p->data;
            }
        }
        printf("%d is maximum in list.\n",max);
    }
}

void Findmin(){
    struct Node *p;
    int min;
    if(head==NULL){
        printf("Empty list");
    }
    else{
        p=head;
        min=p->data;
        for(p=head; p!=NULL; p=p->next){
            if(min>p->data){
                min=p->data;
            }
        }
        printf("%d is minimum in list.\n",min);
    }
}

void LinearSearch(){
    struct Node *p = head;
    if(head == NULL){
        printf("Empty list..\n");
    }
    else{
        int key, flag = 0;
        printf("Enter the value you want to search: ");
        scanf("%d", &key);
        while(p != NULL){
            if(p->data == key){
                printf("%d found in the list.\n", key);
                flag = 1;
                break;
            }
            p = p->next;
        }
        if(flag == 0){
            printf("\nItem not found.\n");
        }
    }
}

void selection_sort(){
    if(head == NULL){
        printf("Empty list..\n");
        return;
    }
    struct Node *p, *q, *min;
    int t;
    for(p = head; p->next != NULL; p=p->next){
        min = p;
        for(q = p->next; q != NULL; q = q->next){
            if(q->data < min->data){
                min = q;
            }
        }
        if(min != p){
            t = min->data;
            min->data = p->data;
            p->data = t;
        }
    }
}
