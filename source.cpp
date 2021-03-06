#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char inputUser[255]; //inputan username
char inputPass[255]; //inputan password

struct User {   //doubly linked list buat data user
    char name[255];
    char pass[255];
    User *prev, *next;
} *head, *tail;

User *createUser(const char *name, const char *pass) {
    User *newUser = (User*)malloc(sizeof(User));
    strcpy(newUser->name, name);
    strcpy(newUser->pass, pass);
     newUser->prev = NULL;
    newUser->next = NULL;
    return newUser;

}

void pushHead(const char *name,const char *pass) {
    User *temp = createUser(name,pass);
    if (!head) {
        head = tail = temp;
    }else {
        head->prev = temp;
        temp->next = head;
        head = temp;
    }
   
}

void printListNameMenu() {
    User *curr = head;
    int nomor = 1;
    while(curr) {
        printf("%d.\t%s\n",nomor,curr->name);
        curr = curr-> next;
        nomor++;
    }
    printf("NULL\n");
}

void printListLoginMenu() {
    User *curr = head;
    int nomor = 1;
    while(curr) {
    	if(strcmp(curr->name, inputUser)!=0){
        	printf("%d.\t%s\n",nomor,curr->name);
        	curr = curr-> next;
        	nomor++;
		}
    }
    printf("NULL\n");
}

void mainPage() {
    printf("Oo=====================================oO\n");
    printf("               STUDY NETWORK                \n");
    printf("Oo=====================================oO\n");
    printf("\n");
    printf("[All User]\n");
    printf("No.   Username\n");
    printListNameMenu();    //data user
    printf("-----------------------------------------\n");
    printf("[1] Register\n");
    printf("[2] Login\n");
    printf("[3] Exit\n");
    printf("-----------------------------------------\n");
    printf(" Press 0 and enter to abort an operation\n");
    printf("-----------------------------------------\n");
    printf(">> ");
}

void registermenu(){
    char namaUser[255];
    char passUser[255];
    printf("-----------------------------------------\n");
    printf("Please type in your username [lowercase||1..24]:");
    scanf("%s",namaUser);
    getchar();
    printf("Please type in your password [lowercase||1..24]:");
    scanf("%s",passUser);
    getchar();
    
    pushHead(namaUser,passUser);
    printf("---Registration Successfull---\n");
    printf("Press enter to continue\n");
    
    getchar();
}

bool loginmenu() {

    printf("-----------------------------------------\n");
    printf("Username: ");
    scanf("%[^\n]",inputUser);
    getchar();
   

    puts("Password: ");
    scanf("%[^\n]",inputPass);
    getchar();
    bool accepted = false;     //kalo berhasil pass sama user sama
    
    User *curr = head;
    while(curr){
        if(strcmp(curr->name,inputUser)==0 && strcmp(curr->pass,inputPass)==0){
            accepted = true;
            break;
        }else if(strcmp(curr->name,inputUser)!=0 && strcmp(curr->pass,inputPass)==0){
            accepted = false;
            break;
        }else if(strcmp(curr->name,inputUser)==0 && strcmp(curr->pass,inputPass)!=0){
            accepted = false;
            break;
        }else{
            accepted = false;
            break;
        }
    }
    if (accepted == true) {
        printf("--- Login Successfull ---\n");
        printf("Press enter to continue\n");
        getchar();
        return true;
    }else if(accepted == false) {
        printf("--- Data Not Registered ---\n");
        printf("Press enter to continue\n");
        getchar();
        return false;
    }
}

struct Friend {
	char name[255];
	Friend *prev, *next;
} *fhead, *ftail;
	
Friend *createFriend(const char *name) {
	Friend *newFriend = (Friend*)malloc(sizeof(Friend));
	strcpy(newFriend->name, name);
	newFriend->prev = NULL;
	newFriend->next = NULL;
	return newFriend;
}

void push(const char *name) {
    Friend *temp = createFriend(name);
    if (!fhead) {
        fhead = ftail = temp;
    }else {
        fhead->prev = temp;
        temp->next = fhead;
        fhead = temp;
    }
}

bool AddFriend(){
	char friendname[255];
	Friend *curr = fhead;
	printf("Which user do you want to add?\n");
	printf(">> ");
	scanf("%s", friendname); getchar();
	printf("\n");
	printf("-- Your request has been sent to %s --\n", friendname);getchar();
	printf("Press enter to continue!\n");getchar();
	push(friendname);getchar();
	while (curr){
		if (strcmp(curr->name, friendname)==0) return true;
	}
}

bool RemoveFriend(){
	
}

bool ViewInbox(){
	char Friendname[255];
	Friend *curr = fhead;
	printf("Which user do you want to be accepted?\n");
	printf(">> ");
	scanf("%s", Friendname); getchar();
	printf("\n");
	printf("-- You accepted the request from %s --\n", Friendname);getchar();
	printf("Press enter to continue!\n");getchar();
	push(Friendname);getchar();
	while (curr){
		if (strcmp(curr->name, Friendname)==0) return true;
	}
}

bool ViewSentRequest(){
	char FriendName[255];
	Friend *curr = fhead;
	printf("Which user do you want to be canceled?\n");
	printf(">> ");
	scanf("%s", FriendName); getchar();
	printf("\n");
	printf("-- You canceled the request from %s --\n", FriendName);getchar();
	printf("Press enter to continue!\n");getchar();
	push(FriendName);getchar();
	while (curr){
		if (strcmp(curr->name, FriendName)==0) return true;
	}
}

void AddEditAnnounceDelete(){
	
}

void printFriendList() {
	char name[255];
	User *curr = head;
    int nomor = 1;
    if(AddFriend()){
    	printf("-----------------------------------------\n");
    	printf("\n");
    	printf("[All User]\n");
    	printf("No. Username\n");
    	while(curr){
    	    if(strcmp(curr->name, inputUser)!=0){
    	    	printf("%d.\t%s\n",nomor,curr->name);
    	    	curr = curr-> next;
    		    nomor++;
			}
   		}
    printf("NULL\n");
    printf("\n");
	} else if (RemoveFriend()){
		printf("-----------------------------------------\n");
    	printf("\n");
    	printf("[All Friends of %s]\n", name);
    	printf("No. Username\n");
    	while(curr){
    		if(strcmp(curr->name, inputUser)!=0){
    			printf("%d.\t%s\n",nomor,curr->name);
    	    	curr = curr-> next;
    	    	nomor++;
			}
		}
		printf("NULL\n");
		printf("\n");
	} else if (ViewInbox()){
		printf("-----------------------------------------\n");
    	printf("\n");
    	printf("[All Friend Requests of %s]\n", name);
    	printf("No. Username\n");
    	while(curr){
    		if(strcmp(curr->name, inputUser)!=0){
    	    	printf("%d.\t%s\n",nomor,curr->name);
    	    	curr = curr-> next;
    	    	nomor++;
				}
		}
		printf("NULL\n");
    	printf("\n");
	} else if (ViewSentRequest()){
		printf("-----------------------------------------\n");
    	printf("\n");
    	printf("[All Sent Friend Requests of %s]\n", name);
    	printf("No. Username\n");
    	while(curr){
    		if(strcmp(curr->name, inputUser)!=0){
    	    	printf("%d.\t%s\n",nomor,curr->name);
    	    	curr = curr-> next;
    	    	nomor++;
				}
		}
		printf("NULL\n");
    	printf("\n");
	}
}

void UserPage() {
	struct tm *Sys_T;
    time_t Tval;
    Tval = time(NULL);
    Sys_T = localtime(&Tval);
    printf("Oo=====================================oO\n");
    printf("Welcome, %s!\n", inputUser);
    printf("Oo=====================================oO\n");
	printf("Logged in: %s\n", asctime (Sys_T));
	printf("-----------------------------------------\n");
	printf("\n");
	printf("[All Friends of %s]\n", inputUser);
	printf("No.   Username\n");
	printListLoginMenu();
	printf("\n");
	printf("-----------------------------------------\n");
	printf("				>>Menu<<				 \n");
	printf("-----------------------------------------\n");
	printf("[1] Add Friend\n");
	printf("[2] Remove Friend\n");
	printf("[3] View Inbox\n");
	printf("[4] View Sent Request\n");
	printf("[5] Add, Edit, Announce, Delete Note\n");
	printf("[6] Log out\n");
	printf("-----------------------------------------\n");
	printf(">> ");
}    
bool exitCommand() {
    return false;
}


int main() {
    int menus;
    bool acc = false;
    bool repeat = true;
    while (repeat) {
        system("cls");
        if (acc == false) {
            mainPage();
            scanf("%d",&menus);getchar();
            switch(menus) {
                case 0: break;
                case 1: registermenu(); break;
                case 2: acc = loginmenu(); break;
                case 3: repeat = exitCommand(); break;
                default: printf("Menu tidak tersedia\n"); break;
            } 
        } else {
            UserPage();    // liat function login page buat menu yang Add Friend
            scanf("%d",&menus);getchar();
            switch(menus) {
                case 0: break;
                case 1: AddFriend();break;
                case 2: RemoveFriend();break;
                case 3: ViewInbox();break;
                case 4: ViewSentRequest();break;
                case 5: AddEditAnnounceDelete();break;
                case 6: return 0;
                default: printf("Menu tidak tersedia\n");break;
            }
        } 
    }
}
