#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef char String[32];

typedef struct {
    int book_id;
    String book_name;
} Book;

typedef struct node {
    Book book;
    struct node *left;
    struct node *right;
} *BST;

void insertNode(BST *root, Book newBook);
void populateBook(BST *root);
void displayBook(BST root);
void Inorder(BST root);
void Preorder(BST root);
void Postorder(BST root);

int main (){
    BST Books = NULL;
    
    populateBook(&Books);
    printf("Preorder:\n");
    Preorder(Books);

    printf("Inorder:\n");
    Inorder(Books);

    printf("Postorder:\n");
    Postorder(Books);
    return 0;
}

void insertNode(BST *root, Book newBook){
    BST* trav;

    for(trav = root; *trav != NULL && (*trav)->book.book_id != newBook.book_id;){
        trav = (newBook.book_id < (*trav)->book.book_id) ? &(*trav)->left : &(*trav)->right;
    }

    if(*trav == NULL){
        *trav = calloc(1, sizeof(struct node));
        if(*trav != NULL){
            (*trav)->book = newBook;
        }
    }
}

void populateBook(BST *root){
    Book books[] = {
        {10, "DSA"},
        {40, "PROG2"},
        {50, "IHATES"},
        {30, "YES"},
        {70, "YOU"},
        };

    int n = sizeof(books) / sizeof(Book);
    for(int i = 0; i < n; i++){
        insertNode(root, books[i]);
    }
}

void Preorder(BST root){
     if(root != NULL){
        printf("ID: %d TITLE: %s \n", root->book.book_id, root->book.book_name);
        Inorder(root->left);
        Inorder(root->right);
    }   
}

void Inorder(BST root){
    if(root != NULL){
        Inorder(root->left);
        printf("ID: %d TITLE: %s \n", root->book.book_id, root->book.book_name);
        Inorder(root->right);
    }
}

void Postorder(BST root){
    if(root != NULL){
        Inorder(root->left);
        Inorder(root->right);
        printf("ID: %d TITLE: %s \n", root->book.book_id, root->book.book_name);
    }
}

void displayBook(BST root){
    if(root->left){

    }
}