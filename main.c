/*
 ===================================================================================================
 Name        : Linked_List.c
 Author      : Mahmoud Abozeid
 Description : The program allows the user to perform various operations on the linked list,
               such as inserting nodes at the beginning or end, inserting nodes after a specific position,
               deleting nodes at the beginning or a specific position, and displaying all the nodes.
 ===================================================================================================
 */

 /*============= INCLUDES =============*/
#include <stdio.h>
#include <stdlib.h>

typedef unsigned int uint32;
typedef unsigned short uint16;
typedef unsigned char uint8;


struct node{
    uint32 NodeData;
    struct node *NodeLink;
};
/* ============= FUNCTION DECLERATION =============*/
void Insert_Node_At_Beginning(struct node **List);
void Insert_Node_At_End(struct node **List);
void Insert_Node_After(struct node *List);
void Delet_Node_At_Beginig(struct node **List);
void Delet_Node(struct node *List);
void Display_All_Nodes(struct node *List);
uint32 Get_Lenght(struct node *List);

struct node *ListHead = NULL;

int main()
{
    uint8 UserChoice = 0;
    uint32 ListLength = 0;
    printf("-> Hello to Single Linked List \n");
    while(1){
        printf("\n");
        printf("===============================\n");
        printf("-> 1) Insert_Node_At_Beginning \n");
        printf("-> 2) Insert_Node_At_End \n");
        printf("-> 3) Insert_Node_After \n");
        printf("-> 4) Delete_Node_At_Beginning \n");
        printf("-> 5) Delete_Node \n");
        printf("-> 6) Display_All_Nodes \n");
        printf("-> 7) Get_Length \n");
        printf("-> 8) Quit from application \n");
        printf("===============================\n");

        printf("\n");
        printf("UserChoice : ");
        scanf("%i", &UserChoice);

        switch(UserChoice){
            case 1:
                Insert_Node_At_Beginning(&ListHead);
            break;
            case 2:
                Insert_Node_At_End(&ListHead);
            break;
            case 3:
                Insert_Node_After(ListHead);
            break;
            case 4:
                Delet_Node_At_Beginig(&ListHead);
            break;
            case 5:
                Delet_Node(ListHead);
            break;
            case 6:
                Display_All_Nodes(ListHead);
            break;
            case 7:
                ListLength = Get_Lenght(ListHead);
                printf("List Length : << %i >> Nodes\n", ListLength);
            break;
            case 8:
                printf("Quit from application \n");
                exit(1);
            break;
            default:
                printf("User Choice out of range !!\n");
            break;
        }
    }
    return 0;
}

/* ============= FUNCTION DEFINITION =============*/
uint32 Get_Lenght(struct node *List){
    struct node *LastNode = NULL;
    uint32 Lenght = 0;
    LastNode = List;
    while(LastNode != NULL){
        LastNode = LastNode->NodeLink;
        Lenght++;
    }
    return Lenght;
}
void Insert_Node_At_Beginning(struct node **List){
    struct node *TempNode = NULL;
    TempNode = (struct node *)malloc(sizeof(struct node));

    if(NULL != TempNode){
        printf("Enter Node Data : ");
        scanf("%d",&TempNode->NodeData);
        /* Check if Linked list is empty */
        if(NULL == *List){/*Linked List is empty */
            TempNode->NodeLink = NULL;
            *List = TempNode;
        }else{
            TempNode->NodeLink = *List;
            *List = TempNode;

        }
    }else{/* No thing */}

}

void Insert_Node_At_End(struct node **List){
    struct node *TempNode = NULL;
    struct node *LastNode = NULL;
    TempNode = (struct node *)malloc(sizeof(struct node));

    if(NULL != TempNode){
        printf("Enter Node Data : ");
        scanf("%d",&TempNode->NodeData);
        TempNode->NodeLink = NULL;
        /* Check if Linked list is empty */
        if(NULL == *List){/*Linked List is empty */
            *List = TempNode;
        }else{/*Linked List is not empty */
            LastNode = *List;
            while(LastNode->NodeLink != NULL){
                LastNode = LastNode->NodeLink;
            }
            LastNode->NodeLink = TempNode;
        }
    }else{/* No thing */}

}
void Insert_Node_After(struct node *List){
    struct node *TempNode = NULL, *NodeLinkCounter = NULL;
    uint32 NodePosition = 0, NodeCounter = 1, ListLenght = 0;

    printf("Enter your Node position (First Node Position = 1) : ");
    scanf("%d",&NodePosition);

    ListLenght = Get_Lenght(List);

    if(NodePosition > ListLenght){
        printf("Invalid Node Position -> List has (%i) Nodes \n ",ListLenght);
    }
    else{
        NodeLinkCounter = List;
        while(NodeCounter < NodePosition){
            NodePosition++;
            NodeLinkCounter = NodeLinkCounter->NodeLink;
        }
        TempNode = (struct node *)malloc(sizeof(struct node));
        if(NULL != TempNode){
            printf("Enter your Data : ");
            scanf("%d",&TempNode->NodeData);
            /* Connect the right side connection */
            TempNode->NodeLink = NodeLinkCounter->NodeLink;
            /* Connect the left side connection */
            NodeLinkCounter->NodeLink = TempNode;
        }
        else{/* No thing */}
    }
}
void Delet_Node_At_Beginig(struct node **List){
    struct node *Temp = *List;
    uint32 Length = 0;
    Length = Get_Lenght(*List);
    if(Length == 0){
        printf("Error the linked list is empty \n");
    }
    else{
        *List = Temp->NodeLink;
        Temp->NodeLink = NULL;
        free(Temp);
    }
}
void Delet_Node(struct node *List){
    struct node *NodeLinkCounter = List;
    struct node *NextNode = List;
    uint32 NodePosition = 0, NodeCounter = 1, ListLenght = 0;

    printf("Enter your Node position (First Node Position = 1) : ");
    scanf("%d",&NodePosition);

    ListLenght = Get_Lenght(List);

    if((NodePosition > ListLenght) || (ListLenght == 1)){
        printf("Invalid Node Position -> List has (%i) Nodes \n ",ListLenght);
    }
    else{
        while(NodeCounter < (NodePosition - 1)){
            NodeCounter++;
            NodeLinkCounter = NodeLinkCounter->NodeLink;
        }
        NextNode = NodeLinkCounter->NodeLink;
        NodeLinkCounter->NodeLink = NextNode->NodeLink;
        free(NextNode);
    }
}
void Display_All_Nodes(struct node *List){
    struct node *Temp = List;
    printf("Nodes Value : ");
    if(NULL == Temp){
            printf("List is Empty!! \n");
    }
    else{
        while(Temp != NULL){
            printf("%i -> ",Temp->NodeData);
            Temp = Temp->NodeLink;
        }
        if(NULL == Temp){
            printf("NULL !!\n");
        }
    }
}
