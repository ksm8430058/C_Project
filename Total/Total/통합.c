#include <stdio.h>
#include <string.h>

#define MAX_NUM 20
#define MAX_SHOP_NUM 20
#define EXCEPT_ON 1
#define EXCEPT_OFF 0
#define Number_of_Customer 30
#define Found_IT 1

// 구매자 구조체 정의

typedef struct {
    int del;
    char name[10];
    char phone[20];
    char address[100];
}customer;

// 레이아웃

void print_Layout();
int Seller_Customer();
void Seller_menu();
void Shop_menu();
void Menu_menu();
void customer_menu(customer customer[]);
int customer_updatemenu();
void movemenu();

// 가게 관련 함수

void selleradd(struct basic bas[], struct count count);
void sellerlook(struct basic bas[], struct count count);
void sellerupdate(struct basic bas[], struct count count);
void sellersh(struct basic bas[], struct count count);
void sellerdel(struct basic bas[], struct count count);
void sellerrecovery(struct basic bas[], struct count count);


// 메뉴 관련 함수

void menuadd(struct SHOP_MENU menu[][MAX_NUM], struct basic bas[], struct count count);
void menuupdate(struct SHOP_MENU menu[][MAX_NUM], struct basic bas[], struct count count);
void menudel(struct SHOP_MENU menu[][MAX_NUM], struct basic bas[], struct count count);
void menurecovery(struct SHOP_MENU menu[][MAX_NUM], struct basic bas[], struct count count);

// 구매자 관련 함수

void Customer_add(customer customer[], struct count count);
void Customer_look(customer customer[], struct count count);
void Customer_update(customer customer[], struct count count);
void Customer_delete(customer customer[], struct count count);
void Customer_recovery(customer customer[], struct count count);
void Customer_order(struct SHOP_MENU menu[][MAX_NUM], struct basic bas[], customer customer[], struct count count);
void Customer_all_look(customer customer[], struct count count);
void Customer_delete_all_look(customer customer[], struct count count);
int Customer_check(char name[]);
void Customer_print_category2();
int Customer_Select(int choice);

// 가게 구조체 정의

struct basic
{
    char name[MAX_NUM], add[MAX_NUM];
    int del, num, nums;

}bas[100]; 

// 메뉴 구조체 정의

struct SHOP_MENU {

    char menu_index[MAX_NUM];
    char menu_name[MAX_NUM];
    int menu_price;
    int menu_except;

}menu[MAX_SHOP_NUM][MAX_NUM];

// 카운트 구조체

struct count
{
    int shop;
    int menu[MAX_NUM];
    int customer;

};

struct count count = { 0, };

int save_menu_count;

int main(void) {

    int Main_choice;

    customer customer[Number_of_Customer]; 

    while (1) { 

        print_Layout();

        Main_choice = Seller_Customer();

        switch (Main_choice) {

        case 1:
            Seller_menu();
            break;
        case 2:
            customer_menu(customer);
            break;
        case 3:
            exit(0);
        }
    }
	return 0;
}

void print_Layout() {

    system("cls");

    printf("                                        \n");
    printf(" **      ****         ★배달의 무성★   \n");
    printf(" **    *                                \n");
    printf(" *** **                                 \n");
    printf(" *******            *************       \n");
    printf(" *******            **************      \n");
    printf(" *******            **************      \n");
    printf(" *******************  ******  ****      \n");
    printf(" ******************* ******** ****      \n");
    printf("  ******              ******            \n");
    printf("   ****                ****             \n");
    printf("                                        \n");

}

void movemenu() {

    printf("\n계속하시려면 엔터키를 누르세요.\n");
    getch();

}

int Seller_Customer() {

    int choice;

    printf("★배달의 무성★\n **오픈이벤트중**\n");
    printf("---------------------------\n");
    printf(" (1) 판매자\n (2) 주문자\n");
    printf("---------------------------\n");
    printf("이동하실 번호를 입력해주세요 : ");

    scanf("%d", &choice);

    return choice;
}

void Seller_menu() {

    system("cls");

    int choice_seller;

    printf("★배달의 무성★\n **오픈이벤트중**\n");
    printf("---------------------------\n");
    printf(" (1) 가게 관리\n (2) 메뉴 관리\n (3) 처음 화면으로\n");
    printf("---------------------------\n");
    printf("이동하실 번호를 입력해주세요 : ");

    scanf("%d", &choice_seller);

    switch (choice_seller) {
        
    case 1:
        Shop_menu();
        break;
    case 2:
        Menu_menu();
        break;
    case 3:
        break;
    }
}

void Shop_menu() {

    int shop_menu;

    system("cls");
    printf("★배달의 무성★\n **오픈이벤트중**\n");
    printf("---------------------------\n");
    printf(" (1) 가게 등록\n (2) 가게 전체보기\n (3) 가게 수정\n (4) 가게 검색\n (5) 가게 삭제\n (6) 가게 복구\n (7) 처음 화면으로\n");
    printf("---------------------------\n");
    printf("이동하실 번호를 입력해주세요 : ");

    scanf("%d", &shop_menu);
    printf("\n");

    switch (shop_menu) {

    case 1:
        selleradd(bas, count);
        count.shop++;
        break;
    case 2:
        sellerlook(bas, count);
        break;
    case 3:
        sellerupdate(bas, count);
        break;
    case 4:
        sellersh(bas, count);
        break;
    case 5:
        sellerdel(bas, count);
        break;
    case 6:
        sellerrecovery(bas, count);
        break;
    case 7:
        break;
    }
}

void Menu_menu() {

    int menu_menu;

    system("cls");
    printf("★배달의 무성★\n **오픈이벤트중**\n");
    printf("---------------------------\n");
    printf(" (1) 메뉴 등록\n (2) 메뉴 수정\n (3) 메뉴 삭제\n (4) 메뉴 복구\n (5) 처음 화면으로\n");
    printf("---------------------------\n");
    printf("이동하실 번호를 입력해주세요 : ");

    scanf("%d", &menu_menu);
    printf("\n");

    switch (menu_menu) {

    case 1:
        menuadd(menu, bas, count);
        count.menu[save_menu_count]++;
        break;
    case 2:
        menuupdate(menu, bas, count);
        break;
    case 3:
        menudel(menu, bas, count);
        break;
    case 4:
        menurecovery(menu, bas, count);
        break;
    case 5:
        break;
    }
}

void customer_menu(customer customer[]) {

    int customer_menu;

    system("cls");
    printf("★배달의 무성★\n **오픈이벤트중**\n");
    printf("---------------------------\n");
    printf(" (1) 고객 등록\n (2) 고객정보 수정\n (3) 고객정보 출력\n (4) 고객 삭제\n (5) 고객 복구\n (6) 주문\n (7) 처음 화면으로\n");
    printf("---------------------------\n");
    printf("이동하실 번호를 입력해주세요 : ");

    scanf("%d%*c", &customer_menu);

    switch (customer_menu) {

    case 1:
        Customer_add(customer, count);
        count.customer++;
        break;
    case 2:

        Customer_update(customer, count);
        break;
    case 3:
        Customer_look(customer, count);
        break;
    case 4:
        Customer_delete(customer, count);
        break;
    case 5:
        Customer_recovery(customer, count);
        break;
    case 6:
        Customer_order(menu, bas, customer, count);
        break;
    case 7:
        break;
    default:
        printf("1~6사이의 숫자를 입력해주세요\n");
    }
}


int Customer_updatemenu() {

    int customer_updatemenu;

    system("cls");
    printf("★배달의 무성★\n **오픈이벤트중**\n");
    printf("---------------------------\n");
    printf(" (1) 이름 수정\n (2) 전화번호 수정\n (3) 주소변경\n (4) 처음 화면으로\n");
    printf("---------------------------\n");
    printf("이동하실 번호를 입력해주세요 : ");
    

    scanf("%d", &customer_updatemenu);

    return customer_updatemenu;
}

void selleradd(struct basic bas[], struct count count)
{
    char names[100];
    char adds[100];

    bas[count.shop].del = 0;
    printf("가게를 등록해주세요 : ");
    scanf("%s", names);
    strcpy(bas[count.shop].name, names);

    printf("주소를 등록해주세요 : ");
    scanf("%s", adds);
    strcpy(bas[count.shop].add, adds);

    printf("전화번호를 입력해주세요 : ");
    scanf("%d%d", &bas[count.shop].num, &bas[count.shop].nums);

    printf("\n");
    printf(" %d   상호명 : %s | 주소 : %s | 전화번호 : %d-%d \n", count.shop + 1, bas[count.shop].name, bas[count.shop].add, bas[count.shop].num, bas[count.shop].nums);
    
    movemenu();

}
void sellerlook(struct basic bas[], struct count count)
{
    int i;
    printf("********가게전체조회창입니다*****\n\n");
    for (i = 0; i < count.shop ; i++)
    {
        if (bas[i].del == 1)
        {
            continue;
        }
        else
        {
            printf("%5d%15s%10s%10d-%d\n", i + 1, bas[i].name, bas[i].add, bas[i].num, bas[i].nums);
        }
    }

    movemenu();
}
void sellerupdate(struct basic bas[], struct count count)
{
    int number, i;

    printf("수정할 가게번호를 입력해주세요 : ");
    scanf("%d", &number);

    for (i = 0; i < count.shop ; i++)
    {
        if (i == number - 1)
        {
            if (bas[i].del == 1)
            {
                printf("이미 삭제된 가게입니다.\n");
            }
            else {
                printf("수정하실 상호명(공백없이)을 입력해주세요 : ");
                scanf("%s", &bas[i].name);
                printf("주소를 입력해주세요 : ");
                scanf("%s", &bas[i].add);
                printf("전화번호를 입력해주세요 : ");
                scanf("%d%d", &bas[i].num, &bas[i].nums);
                printf("\n");

                printf("상호명 : %s | 주소 : %s | 전화번호 : %d-%d로 수정되었습니다.\n", bas[i].name, bas[i].add, bas[i].num, bas[i].nums);
            }
        }
    }

    movemenu();
}

void sellersh(struct basic bas[], struct count count)
{
    int count1 = 0, i;
    char name[100];

    printf("검색할 가게이름을 입력해주세요 : ");
    scanf("%s", name);
    printf("\n");
    
    for (i = 0; i < count.shop ; i++)
    {
        if (!strcmp(name, bas[i].name))
        {
            if (bas[i].del == 1)
            {
                printf("삭제된 가게입니다.\n");
                count1 = 1;
            }
            else
            {
                printf("%5d%10s%10s%10d-%d", bas[i].name, bas[i].add, bas[i].num, bas[i].nums);
                printf("  감사합니다.\n");
                count1 = 1;
            }
        }
        else if (i == count.shop - 1 && count1 == 0)
        {
            printf("찾으시는 가게가 없습니다.\n");
        }
    }
    movemenu();
}

void sellerdel(struct basic bas[], struct count count)
{
    int number, count1 = 0, i, j;


    printf("★배달의 무성★\n **오픈이벤트중**\n");
    printf("---------------------------\n");
    printf("삭제할 가게번호를 입력해주세요 : ");
    scanf("%d", &number);

    for (i = 0; i < count.shop ; i++)
    {
        if (i == number - 1)
        {
            if (bas[i].del == 1)
            {
                printf("이미 삭제된 가게 입니다.\n");
                count1 = 1;
            }
            else
            {
                bas[i].del = 1;
                count1 = 1;
            }
        }
        else if (i == count.shop - 1 && count1 == 0)
        {
            printf("찾으시는 가게가 없습니다.\n");

        }
    }
    movemenu();
}

void sellerrecovery(struct basic bas[], struct count count) {

    int choice = 0, number = 0;

    while (1)
    {
        //등록된 고객이 있을 경우 
        printf("복구하려는 가게번호를 입력해주세요 : ");
        scanf("%d", &number);
        for (int i = 0; i < count.shop; i++)
        {
            if (i == number)
            {
                if (bas[i].del == 0)
                {
                    printf("삭제된 가게가 아닙니다.\n");
                }
                else
                {
                    printf(" %s %10s %10d-%d\n", bas[i].name, bas[i].add, bas[i].num, bas[i].nums);
                    bas[i].del = 0;
                    printf(" %s가게가 복구되었습니다.\n", bas[i].name);
                    break;
                }
            }
            else if (i == count.shop - 1) //다 찾아봐도 없을경우 
            {
                printf("삭제하려는 가게를 찾을수가 없습니다. \n");
                break;
            }
        }
        break;
    }
    movemenu();
}

void menuadd(struct SHOP_MENU menu[][MAX_NUM], struct basic bas[], struct count count) {

    system("cls");

    if (count.shop > 0) {

        printf("\n (1) 메뉴를 등록합니다\n\n");

        int select_shop;

        for (int i = 0; i < count.shop; i++) {

            puts("  번호       상호명       주소       전화번호    ");
            puts("==================================================");
            printf("%5d%15s%12s%8d-%d\n", i + 1, bas[i].name, bas[i].add, bas[i].num, bas[i].nums);
        }
        printf("\n");

        printf("메뉴를 등록할 가게번호를 검색하세요 : ");
        scanf("%d", &select_shop);
        printf("\n");


        for (int i = 0; i < count.shop; i++) {

            if (i == select_shop - 1) {

                printf("품목명을 입력하세요 : ");
                scanf("%s", menu[select_shop - 1][count.menu[select_shop - 1]].menu_index);
                printf("메뉴명을 입력하세요 : ");
                scanf("%s", menu[select_shop - 1][count.menu[select_shop - 1]].menu_name);
                printf("가격을 입력하세요 : ");
                scanf("%d", &menu[select_shop - 1][count.menu[select_shop - 1]].menu_price);

                menu[select_shop - 1][count.menu[select_shop - 1]].menu_except = EXCEPT_OFF;

                save_menu_count = select_shop - 1;

                break;
            }

            else if (i == count.shop - 1) {

                printf("해당하는 가게가 없습니다.\n");

            }
        }
    }
    else printf("\n가게를 먼저 등록해주세요.\n");

    movemenu();
}

void menuupdate(struct SHOP_MENU menu[][MAX_NUM], struct basic bas[], struct count count) {

    int menu_search, modify_num, select_shop;
    char modify_index[MAX_NUM];
    char modify_name[MAX_NUM];
    int modify_price;

    system("cls");

    if (count.shop > 0) {
        printf("\n");
        puts(" ==== 메뉴 수정 ==== ");
        printf("\n");

        for (int i = 0; i < count.shop; i++) {

            puts("  번호       상호명       주소       전화번호    ");
            puts("==================================================");
            printf("%5d%15s%12s%8d-%d\n", i + 1, bas[i].name, bas[i].add, bas[i].num, bas[i].nums);

        }

        printf("\n");
        printf("메뉴를 수정할 가게 번호를 입력하세요 : ");
        scanf("%d", &select_shop);
        printf("\n");

        for (int i = 0; i < count.shop; i++) {
            if (i == select_shop - 1) {
                if (count.menu[select_shop - 1] < 1) {

                    printf("등록된 메뉴가 없습니다.");
                }
                else if (count.menu[select_shop - 1] < MAX_NUM) {
                    for (int j = 0; j < count.menu[select_shop - 1]; j++) {

                        if (menu[select_shop - 1][j].menu_except == 0)

                            puts("  번호       품목       메뉴명       가격    ");
                            puts("================================================");
                            printf("%5d%12s%14s%11d\n", j + 1, menu[select_shop - 1][j].menu_index, menu[select_shop - 1][j].menu_name, menu[select_shop - 1][j].menu_price);
                    }

                    printf("\n");
                    printf("수정하고 싶은 메뉴 번호를 입력해주세요 : ");
                    scanf("%d", &menu_search);
                    printf("\n");

                    printf("메뉴 품목을 입력해주세요 : ");
                    scanf("%s", modify_index);
                    strcpy(menu[select_shop - 1][menu_search - 1].menu_index, modify_index);

                    printf("메뉴 이름을 입력해주세요 : ");
                    scanf("%s", modify_name);
                    strcpy(menu[select_shop - 1][menu_search - 1].menu_name, modify_name);

                    printf("메뉴 가격을 입력해주세요 : ");
                    scanf("%d", &modify_price);
                    menu[select_shop - 1][menu_search - 1].menu_price = modify_price;

                }
            }

            else if (i == count.shop - 1) {

                printf("해당하는 가게가 없습니다.\n");
            }
        }

    }

    else printf("\n가게를 먼저 등록해주세요.\n");

    movemenu();
}

void menudel(struct SHOP_MENU menu[][MAX_NUM], struct basic bas[], struct count count) {

    int delete_search, delete_search2;

    system("cls");

    if (count.shop > 0) {

        printf("\n");
        puts(" ==== 메뉴 삭제 ==== ");
        printf("\n");

        for (int i = 0; i < count.shop; i++) {

            puts("  번호       상호명       주소       전화번호    ");
            puts("==================================================");
            printf("%5d%15s%12s%8d-%d\n", i + 1, bas[i].name, bas[i].add, bas[i].num, bas[i].nums);

        }

        printf("\n");
        printf("메뉴를 삭제할 가게 번호을 입력하세요 : ");
        scanf("%d", &delete_search);
        printf("\n");
        for (int i = 0; i < count.shop; i++) {
            if (i == delete_search - 1) {
                if (count.menu[delete_search - 1] < 1) {

                    printf("등록된 메뉴가 없습니다.");
                }
                else if (count.menu[delete_search - 1] < MAX_NUM) {
                    for (int j = 0; j < count.menu[delete_search - 1]; j++) {

                        if (menu[delete_search - 1][j].menu_except == 0)
                            puts("  번호       품목       메뉴명       가격    ");
                            puts("================================================");
                            printf("%5d%12s%14s%11d\n", j + 1, menu[delete_search - 1][j].menu_index, menu[delete_search - 1][j].menu_name, menu[delete_search - 1][j].menu_price);

                    }

                    printf("\n");
                    printf("삭제하고 싶은 메뉴 번호를 입력해주세요 : ");
                    scanf("%d", &delete_search2);
                    printf("\n");

                    menu[delete_search - 1][delete_search2 - 1].menu_except = EXCEPT_ON;
                }
            }

            else if (i == count.shop - 1) {

                printf("해당하는 가게가 없습니다.\n");

            }
        }
    }
    else printf("\n가게를 먼저 등록해주세요.\n");

    movemenu();
}
void menurecovery(struct SHOP_MENU menu[][MAX_NUM], struct basic bas[], struct count count) {

    int backup_num, backup_search, backup_search2;
  

    system("cls");

    if (count.shop > 0) {

        printf("\n");
        puts(" ==== 메뉴 복구 ==== ");
        printf("\n");

        for (int i = 0; i < count.shop; i++) {

            puts("  번호       상호명       주소       전화번호    ");
            puts("==================================================");
            printf("%5d%15s%12s%8d-%d\n", i + 1, bas[i].name, bas[i].add, bas[i].num, bas[i].nums);

        }

        printf("\n");
        printf("메뉴를 복구할 가게 번호를 입력하세요 : ");
        scanf("%d", &backup_search);
        printf("\n");
        for (int i = 0; i < count.shop; i++) {
            if (i == backup_search - 1) {
                if (count.menu[backup_search - 1] < 1) {

                    printf("등록된 메뉴가 없습니다.");
                }
                else if (count.menu[backup_search - 1] < MAX_NUM) {
                    printf(" \n == 삭제 된 항목 == \n\n");
                    for (int j = 0; j < count.menu[backup_search - 1]; j++) {

                        if (menu[backup_search - 1][j].menu_except == 1)
                            puts("  번호       품목       메뉴명       가격    ");
                            puts("================================================");
                            printf("%5d%12s%14s%11d\n", j + 1, menu[backup_search - 1][j].menu_index, menu[backup_search - 1][j].menu_name, menu[backup_search - 1][j].menu_price);
                    }

                    printf("\n");
                    printf("복구하고 싶은 메뉴 번호를 입력해주세요 : ");
                    scanf("%d", &backup_search2);

                    printf("\n");

                    menu[backup_search - 1][backup_search2 - 1].menu_except = EXCEPT_OFF;
                }
            }
            else if (i == count.shop - 1) {

                printf("해당하는 가게가 없습니다.\n");

            }
        }

    }
    
    else printf("\n가게를 먼저 등록해주세요.\n");

    movemenu();
}

//고객 입력
void Customer_add(customer customer[], struct count count)
{
    char name1[10], call[20], address[100];
    customer[count.customer].del = 0;
    system("cls");
    printf("   <고객등록페이지>   \n\n");
    printf("사용자 이름을 입력해주세요: ");
    gets(customer[count.customer].name);
    printf("사용자 전화번호를 입력해주세요: ");
    gets(customer[count.customer].phone);
    printf("사용자 주소를 입력해주세요: ");
    gets(customer[count.customer].address);
    printf("사용자 정보가 입력되었습니다.\n");

    movemenu();
}

//고객 업데이트
void Customer_update(customer customer[], struct count count)
{
    int choice = 0, number = 0;
    char name[10], name1[10], call[20], address[100];
    while (1)
    {
        if (count.customer == 0) //등록된 고객이 한명도 없을 때
        {
            printf("등록된 고객이 한명도 없습니다.\n");
        }
        else
        { //등록된 고객이 있을 경우 
            printf("수정하려는 고객번호를 입력해주세요: ");
            scanf("%d%*c", &number);
            for (int i = 0; i < count.customer; i++)
            {
                if (i == number) //찾는 고객이 있을 경우
                {
                    if (customer[i].del == 1)
                    {
                        printf("이미 지워진 고객입니다.\n");
                        break;
                    }
                    else
                    {
                        printf("번호   이름      전화번호      주소\n");
                        printf("----------------------------------------------------------------\n");
                        printf("%3d %10s %18s %18s\n", i, customer[i].name, customer[i].phone, customer[i].address);
                        Customer_print_category2();
                        while (1)
                        {
                            choice = Customer_Select(choice);
                            switch (choice)
                            {
                            case 1:
                                printf("수정할 이름을 입력해주세요: ");
                                scanf("%s", name1);
                                strcpy(customer[i].name, name1);
                                printf("이름이 %s으로 수정되었습니다.\n\n", customer[i].name);
                                break;
                            case 2:
                                printf("수정할 전화번호를 입력해주세요: ");
                                scanf("%s", call);
                                strcpy(customer[i].phone, call);
                                printf("전화번호가 %s으로 수정되었습니다.\n\n", customer[i].phone);
                                break;
                            case 3:
                                printf("수정할 주소를 입력해주세요: ");
                                gets(address);
                                strcpy(customer[i].address, address);
                                printf("주소가 %s으로 수정되었습니다.\n\n", customer[i].address);
                                break;
                            default:
                                printf("1~3사이의 숫자를 입력해주세요\n");
                                break;
                            }
                            break;
                        }
                    }
                    break;
                }
                else if (i == count.customer - 1) //다 찾아봐도 없을경우 
                {
                    printf("해당하는 고객이 없습니다. \n");
                    break;
                }
            }
        }
        movemenu();
        break;
    }
}

//고객 출력
void Customer_look(customer customer[], struct count count)
{
    int choice = 0, count1 = 0, count2 = 0;
    char name[20];
    system("cls");
    while (1)
    {
        if (count.customer == 0) //등록된 고객이 한명도 없을 때
        {
            printf("등록된 고객이 한명도 없습니다.\n");
            break;
        }
        else
        { //등록된 고객이 있을 경우 
            printf("모든 고객을 출력하시려면 1을 입력하시거나\n");
            printf("찾으시려는 고객명을 입력해주세요: ");
            scanf("%s%*c", name);
            if (!strcmp("1", name))
            {
                Customer_all_look(customer, count);
                count1 = Found_IT;
            }
            for (int i = 0; i < count.customer; i++)
            {
                if (!strcmp(customer[i].name, name)) //찾는 고객이 있을 경우
                {
                    if (customer[i].del == 1)
                    {
                        printf("이미 지워진 고객입니다.\n");
                        count1 = Found_IT;
                    }
                    else
                    {
                        if (count2 == 0)
                        {
                            printf("%s에 해당하는 고객을 찾았습니다.\n", name);
                            printf("번호   이름      전화번호      주소\n");
                            printf("----------------------------------------------------------------\n");
                            printf("%3d %10s %18s %18s\n", i, customer[i].name, customer[i].phone, customer[i].address);
                            count1 = Found_IT;
                            count2 = Found_IT;
                        }
                        else
                        {
                            printf("%3d    %s   %s   %13s\n", i, customer[i].name, customer[i].phone, customer[i].address);
                            count1 = Found_IT;
                        }
                    }
                }
                else if (i == count.customer - 1 && count1 != Found_IT) //다 찾아봐도 없을경우 
                {
                    printf("%s에 해당하는 고객이 없습니다. \n", name);
                }
            }
        }
        movemenu();
        break;
    }
}

//고객 삭제
void Customer_delete(customer customer[], struct count count)
{
    int choice = 0, number = 0, count1 = 0;;
    char name[10];
    char name2[10];
    while (1)
    {
        if (count.customer == 0) //등록된 고객이 한명도 없을 때
        {
            printf("등록된 고객이 한명도 없습니다.\n");
        }
        else
        { //등록된 고객이 있을 경우 
            printf("삭제된 모든 고객을 출력하시려면 s를 입력하시거나\n");
            printf("삭제하시려는 고객번호를 입력해주세요: ");
            scanf("%s%*c", name);
            if (!strcmp("s", name))
            {
                Customer_delete_all_look(customer, count);
                count1 = Found_IT;

            }
            for (int i = 0; i < count.customer; i++)
            {
                if (i == atoi(name) && Customer_check(name) == 0) //찾는 고객이 있을 경우
                {
                    if (customer[i].del == 1)
                    {
                        printf("이미 지워진 고객입니다.\n");
                        count1 == Found_IT;
                    }
                    else
                    {
                        printf("%s에 해당하는 고객을 찾았습니다.\n", customer[i].name);
                        printf("번호   이름      전화번호      주소\n");
                        printf("----------------------------------------------------------------\n");
                        printf("%3d %10s %18s %18s\n", i, customer[i].name, customer[i].phone, customer[i].address);
                        printf("정말로 삭제하시겠습니까?\n");
                        printf("삭제하시려면 고객이름을 입력해주세요: ");
                        scanf("%s", name2);
                        if (!strcmp(customer[i].name, name2)) //입력해서 같을 경우 
                        {
                            customer[i].del = 1;
                            printf("%s 고객이 삭제되었습니다.\n", customer[i].name);
                            count1 == Found_IT;
                        }
                        else
                        {
                            printf("삭제하려는 고객명이 틀립니다.\n");
                            count1 == Found_IT;
                        }
                    }
                    break;
                }
                else if (i == count.customer - 1 && count1 != Found_IT) //다 찾아봐도 없을경우 
                {
                    printf("해당하는 고객이 없습니다. \n");
                    break;
                }
            }
        }
        movemenu();
        break;

    }
}

//고객 복구
void Customer_recovery(customer customer[], struct count count)
{
    int choice = 0, number = 0, count1 = 0;
    char name[10];
    char name2[10];
    while (1)
    {
        if (count.customer == 0) //등록된 고객이 한명도 없을 때
        {
            printf("등록된 고객이 한명도 없습니다.\n");
            count1 == Found_IT;
        }
        else
        { //등록된 고객이 있을 경우 
            printf("복구하려는 고객번호를 입력해주세요: ");
            scanf("%d", &number);
            for (int i = 0; i < count.customer; i++)
            {
                if (i == number)
                {
                    if (customer[i].del == 0)
                    {
                        printf("삭제된 회원이 아닙니다.\n");
                    }
                    else
                    {
                        printf("삭제된 고객 %s를 찾았습니다.\n", customer[i].name);
                        printf("번호   이름      전화번호      주소\n");
                        printf("----------------------------------------------------------------\n");
                        printf("%3d %10s %18s %18s\n", i, customer[i].name, customer[i].phone, customer[i].address);
                        printf("복구하시려면 이름을 다시 입력해주세요: ");
                        scanf("%s%*c", name2);
                        if (!strcmp(customer[i].name, name2)) //다시입력해서 같을 경우 
                        {
                            customer[i].del = 0;
                            printf("%s 고객이 복구되었습니다.\n", customer[i].name);
                            count1 = Found_IT;
                        }
                        else
                        {
                            printf("복구하려는 고객명이 틀립니다.\n");
                            count1 = Found_IT;
                        }
                    }
                }
                else if (i == count.customer - 1 && count1 != Found_IT) //다 찾아봐도 없을경우 
                {
                    printf("복구하려는 고객을 찾을수가 없습니다. \n");
                }
            }
        }
        movemenu();
        break;
    }
}

//고객 update 카테고리 
void Customer_print_category2() {
    printf("(1) 이름 수정 \n");
    printf("(2) 전화번호 수정 \n");
    printf("(3) 주소변경 \n");
}

//스위치문 선택 
int Customer_Select(int choice)
{
    printf("항목을 선택해주세요: ");
    scanf("%d%*c", &choice);
    return choice;
}

//고객 전체 출력 
void Customer_all_look(customer customer[], struct count count)
{
    printf("번호   이름      전화번호      주소\n");
    printf("----------------------------------------------------------------\n");
    for (int i = 0; i < count.customer; i++)
    {
        if (customer[i].del == 1)
            continue;
        else
        {
            printf("%3d %10s %18s %18s", i, customer[i].name, customer[i].phone, customer[i].address);
            printf("\n");
        }
    }
}

//삭제된 고객 전체 출력 
void Customer_delete_all_look(customer customer[], struct count count)
{
    int count1 = 0;

    for (int i = 0; i < count.customer; i++)
    {
        if (customer[i].del == 1)
            count1 = 1;
    }

    if (count1 == 1)
    {
        printf("번호   이름      전화번호      주소\n");
        printf("----------------------------------------------------------------\n");
        for (int i = 0; i < count.customer; i++)
        {
            if (customer[i].del == 0)
                continue;
            else
            {
                printf("%3d    %s   %s   %13s", i, customer[i].name, customer[i].phone, customer[i].address);
                printf("\n");
            }
        }
    }
    else
        printf("삭제된 고객이 한명도 없습니다.\n");
}

//테스트 데이터
void testdata(customer customer[])
{
    strcpy(customer[0].name, "김김김");
    strcpy(customer[0].phone, "010-2352-7813");
    strcpy(customer[0].address, "남천동");
    customer[0].del = 0;

    strcpy(customer[1].name, "남궁김김");
    strcpy(customer[1].phone, "010-3209-1557");
    strcpy(customer[1].address, "대연동");
    customer[1].del = 0;
}

//숫자인지 체크
int Customer_check(char name[])
{
    for (int i = 0; i < 10; i++) {
        if ('0' <= name[i] && name[i] <= '9')
            return 0;
    }
    return 1;
}

void Customer_order(struct SHOP_MENU menu[][MAX_NUM], struct basic bas[], customer customer[], struct count count)
{
    int menu_search, select_shop, count1 = 0, count2 = 0;

    system("cls");
    //가게 없을때
    if (count.shop == 0)
    {
        printf("등록된 가게가 없습니다. 나중에 다시 시도해주세요");
    }
    //가게 있을 경우 
    else
    {
        printf("\n");
        puts(" ============== 가게 목록 ============== ");
        printf("\n");
        //있는 가게 출력해주고(삭제된건 아직 고려 안됨)
        for (int i = 0; i < count.shop; i++) {

            puts("  번호       상호명       주소       전화번호    ");
            puts("==================================================");
            printf("%5d%15s%12s%8d-%d\n", i + 1, bas[i].name, bas[i].add, bas[i].num, bas[i].nums);

        }
        //가게 번호 선택 
        printf("\n");
        printf("주문할 가게번호를 입력하세요 : ");
        scanf("%d", &select_shop);
        printf("\n");
        //가게 번호 있는지 확인 
        for (int i = 0; i < count.shop; i++)
        {
            //삭제됬을 경우
            if (bas[count.shop - 1].del == 1)
            {
                printf("삭제된 가게입니다.\n");
                count1 = Found_IT;

            }
            //있는가게일 경우 
            else if (select_shop - 1 == i)
            {
                //메뉴가 없을경우 
                if (count.menu[select_shop - 1] < 1)
                {
                    printf("등록된 메뉴가 없습니다.");
                    count1 = Found_IT;
                }

                //가게에 메뉴가 있을경우 출력
                else if (count.menu[select_shop - 1] < MAX_NUM)
                {
                    for (int j = 0; j < count.menu[select_shop - 1]; j++)
                    {
                        //지워진 메뉴가 아닐경우 
                        if (menu[select_shop - 1][j].menu_except == 0)
                            puts("  번호       품목       메뉴명       가격    ");
                            puts("================================================");
                            printf("%5d%12s%14s%11d\n", j + 1, menu[select_shop - 1][j].menu_index, menu[select_shop - 1][j].menu_name, menu[select_shop - 1][j].menu_price);
                    }
                    printf("\n");
                    printf("주문 하고 싶은 메뉴 번호를 입력해주세요 : ");
                    scanf("%d", &menu_search);
                    for (int k = 0; k < count.menu[select_shop - 1]; k++)
                    {
                        if (menu_search - 1 == k)
                        {
                            printf("\n");
                            printf("%s 메뉴가 주문 완료 되었습니다.\n ", menu[select_shop - 1][menu_search - 1].menu_name);
                            printf("\n");
                            puts(" ┌────────────────────────────────────────────────────────────┐");
                            puts(" │                                                            │");
                            puts(" │                                                            │");
                            puts(" │ ====================== < 영 수 증 > =======================│");
                            puts(" │                                                            │");
                            puts(" │                                                            │");
                            printf(" │  상호명 : %5s   전화번호 : %5d-%d   주소 : %5s │\n", bas[select_shop - 1].name, bas[select_shop - 1].num, bas[select_shop - 1].nums, bas[select_shop - 1].add);
                            puts(" │                                                            │");
                            puts(" │                                                            │");
                            printf(" │        주문메뉴 : %5s       가격 : %5d원            │\n", menu[select_shop - 1][menu_search - 1].menu_name, menu[select_shop - 1][menu_search - 1].menu_price);
                            puts(" │                                                            │");
                            puts(" │                                                            │");
                            puts(" │ ===========================================================│");
                            puts(" │                                                            │");
                            puts(" │                                                            │");
                            puts(" └────────────────────────────────────────────────────────────┘");
                            count2 = Found_IT;
                        }
                        else if (k == count.menu[select_shop - 1] - 1 && count2 != Found_IT)
                            printf("없는 번호를 입력했습니다. 다시 입력해주세요.");
                    }
                }
                count1 = Found_IT;
            }
            //없는 가게일 경우
            else if (i == count.shop - 1 && count1 != Found_IT)
            {
                printf("가게번호를 제대로 입력해주세요\n");
            }
        }
    }

    movemenu();
}