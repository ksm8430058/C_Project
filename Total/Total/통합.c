#include <stdio.h>
#include <string.h>

#define MAX_NUM 20
#define MAX_SHOP_NUM 20
#define EXCEPT_ON 1
#define EXCEPT_OFF 0
#define Number_of_Customer 30
#define Found_IT 1

// ������ ����ü ����

typedef struct {
    int del;
    char name[10];
    char phone[20];
    char address[100];
}customer;

// ���̾ƿ�

void print_Layout();
int Seller_Customer();
void Seller_menu();
void Shop_menu();
void Menu_menu();
void customer_menu(customer customer[]);
int customer_updatemenu();
void movemenu();

// ���� ���� �Լ�

void selleradd(struct basic bas[], struct count count);
void sellerlook(struct basic bas[], struct count count);
void sellerupdate(struct basic bas[], struct count count);
void sellersh(struct basic bas[], struct count count);
void sellerdel(struct basic bas[], struct count count);
void sellerrecovery(struct basic bas[], struct count count);


// �޴� ���� �Լ�

void menuadd(struct SHOP_MENU menu[][MAX_NUM], struct basic bas[], struct count count);
void menuupdate(struct SHOP_MENU menu[][MAX_NUM], struct basic bas[], struct count count);
void menudel(struct SHOP_MENU menu[][MAX_NUM], struct basic bas[], struct count count);
void menurecovery(struct SHOP_MENU menu[][MAX_NUM], struct basic bas[], struct count count);

// ������ ���� �Լ�

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

// ���� ����ü ����

struct basic
{
    char name[MAX_NUM], add[MAX_NUM];
    int del, num, nums;

}bas[100]; 

// �޴� ����ü ����

struct SHOP_MENU {

    char menu_index[MAX_NUM];
    char menu_name[MAX_NUM];
    int menu_price;
    int menu_except;

}menu[MAX_SHOP_NUM][MAX_NUM];

// ī��Ʈ ����ü

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
    printf(" **      ****         �ڹ���� ������   \n");
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

    printf("\n����Ͻ÷��� ����Ű�� ��������.\n");
    getch();

}

int Seller_Customer() {

    int choice;

    printf("�ڹ���� ������\n **�����̺�Ʈ��**\n");
    printf("---------------------------\n");
    printf(" (1) �Ǹ���\n (2) �ֹ���\n");
    printf("---------------------------\n");
    printf("�̵��Ͻ� ��ȣ�� �Է����ּ��� : ");

    scanf("%d", &choice);

    return choice;
}

void Seller_menu() {

    system("cls");

    int choice_seller;

    printf("�ڹ���� ������\n **�����̺�Ʈ��**\n");
    printf("---------------------------\n");
    printf(" (1) ���� ����\n (2) �޴� ����\n (3) ó�� ȭ������\n");
    printf("---------------------------\n");
    printf("�̵��Ͻ� ��ȣ�� �Է����ּ��� : ");

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
    printf("�ڹ���� ������\n **�����̺�Ʈ��**\n");
    printf("---------------------------\n");
    printf(" (1) ���� ���\n (2) ���� ��ü����\n (3) ���� ����\n (4) ���� �˻�\n (5) ���� ����\n (6) ���� ����\n (7) ó�� ȭ������\n");
    printf("---------------------------\n");
    printf("�̵��Ͻ� ��ȣ�� �Է����ּ��� : ");

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
    printf("�ڹ���� ������\n **�����̺�Ʈ��**\n");
    printf("---------------------------\n");
    printf(" (1) �޴� ���\n (2) �޴� ����\n (3) �޴� ����\n (4) �޴� ����\n (5) ó�� ȭ������\n");
    printf("---------------------------\n");
    printf("�̵��Ͻ� ��ȣ�� �Է����ּ��� : ");

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
    printf("�ڹ���� ������\n **�����̺�Ʈ��**\n");
    printf("---------------------------\n");
    printf(" (1) �� ���\n (2) ������ ����\n (3) ������ ���\n (4) �� ����\n (5) �� ����\n (6) �ֹ�\n (7) ó�� ȭ������\n");
    printf("---------------------------\n");
    printf("�̵��Ͻ� ��ȣ�� �Է����ּ��� : ");

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
        printf("1~6������ ���ڸ� �Է����ּ���\n");
    }
}


int Customer_updatemenu() {

    int customer_updatemenu;

    system("cls");
    printf("�ڹ���� ������\n **�����̺�Ʈ��**\n");
    printf("---------------------------\n");
    printf(" (1) �̸� ����\n (2) ��ȭ��ȣ ����\n (3) �ּҺ���\n (4) ó�� ȭ������\n");
    printf("---------------------------\n");
    printf("�̵��Ͻ� ��ȣ�� �Է����ּ��� : ");
    

    scanf("%d", &customer_updatemenu);

    return customer_updatemenu;
}

void selleradd(struct basic bas[], struct count count)
{
    char names[100];
    char adds[100];

    bas[count.shop].del = 0;
    printf("���Ը� ������ּ��� : ");
    scanf("%s", names);
    strcpy(bas[count.shop].name, names);

    printf("�ּҸ� ������ּ��� : ");
    scanf("%s", adds);
    strcpy(bas[count.shop].add, adds);

    printf("��ȭ��ȣ�� �Է����ּ��� : ");
    scanf("%d%d", &bas[count.shop].num, &bas[count.shop].nums);

    printf("\n");
    printf(" %d   ��ȣ�� : %s | �ּ� : %s | ��ȭ��ȣ : %d-%d \n", count.shop + 1, bas[count.shop].name, bas[count.shop].add, bas[count.shop].num, bas[count.shop].nums);
    
    movemenu();

}
void sellerlook(struct basic bas[], struct count count)
{
    int i;
    printf("********������ü��ȸâ�Դϴ�*****\n\n");
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

    printf("������ ���Թ�ȣ�� �Է����ּ��� : ");
    scanf("%d", &number);

    for (i = 0; i < count.shop ; i++)
    {
        if (i == number - 1)
        {
            if (bas[i].del == 1)
            {
                printf("�̹� ������ �����Դϴ�.\n");
            }
            else {
                printf("�����Ͻ� ��ȣ��(�������)�� �Է����ּ��� : ");
                scanf("%s", &bas[i].name);
                printf("�ּҸ� �Է����ּ��� : ");
                scanf("%s", &bas[i].add);
                printf("��ȭ��ȣ�� �Է����ּ��� : ");
                scanf("%d%d", &bas[i].num, &bas[i].nums);
                printf("\n");

                printf("��ȣ�� : %s | �ּ� : %s | ��ȭ��ȣ : %d-%d�� �����Ǿ����ϴ�.\n", bas[i].name, bas[i].add, bas[i].num, bas[i].nums);
            }
        }
    }

    movemenu();
}

void sellersh(struct basic bas[], struct count count)
{
    int count1 = 0, i;
    char name[100];

    printf("�˻��� �����̸��� �Է����ּ��� : ");
    scanf("%s", name);
    printf("\n");
    
    for (i = 0; i < count.shop ; i++)
    {
        if (!strcmp(name, bas[i].name))
        {
            if (bas[i].del == 1)
            {
                printf("������ �����Դϴ�.\n");
                count1 = 1;
            }
            else
            {
                printf("%5d%10s%10s%10d-%d", bas[i].name, bas[i].add, bas[i].num, bas[i].nums);
                printf("  �����մϴ�.\n");
                count1 = 1;
            }
        }
        else if (i == count.shop - 1 && count1 == 0)
        {
            printf("ã���ô� ���԰� �����ϴ�.\n");
        }
    }
    movemenu();
}

void sellerdel(struct basic bas[], struct count count)
{
    int number, count1 = 0, i, j;


    printf("�ڹ���� ������\n **�����̺�Ʈ��**\n");
    printf("---------------------------\n");
    printf("������ ���Թ�ȣ�� �Է����ּ��� : ");
    scanf("%d", &number);

    for (i = 0; i < count.shop ; i++)
    {
        if (i == number - 1)
        {
            if (bas[i].del == 1)
            {
                printf("�̹� ������ ���� �Դϴ�.\n");
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
            printf("ã���ô� ���԰� �����ϴ�.\n");

        }
    }
    movemenu();
}

void sellerrecovery(struct basic bas[], struct count count) {

    int choice = 0, number = 0;

    while (1)
    {
        //��ϵ� ���� ���� ��� 
        printf("�����Ϸ��� ���Թ�ȣ�� �Է����ּ��� : ");
        scanf("%d", &number);
        for (int i = 0; i < count.shop; i++)
        {
            if (i == number)
            {
                if (bas[i].del == 0)
                {
                    printf("������ ���԰� �ƴմϴ�.\n");
                }
                else
                {
                    printf(" %s %10s %10d-%d\n", bas[i].name, bas[i].add, bas[i].num, bas[i].nums);
                    bas[i].del = 0;
                    printf(" %s���԰� �����Ǿ����ϴ�.\n", bas[i].name);
                    break;
                }
            }
            else if (i == count.shop - 1) //�� ã�ƺ��� ������� 
            {
                printf("�����Ϸ��� ���Ը� ã������ �����ϴ�. \n");
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

        printf("\n (1) �޴��� ����մϴ�\n\n");

        int select_shop;

        for (int i = 0; i < count.shop; i++) {

            puts("  ��ȣ       ��ȣ��       �ּ�       ��ȭ��ȣ    ");
            puts("==================================================");
            printf("%5d%15s%12s%8d-%d\n", i + 1, bas[i].name, bas[i].add, bas[i].num, bas[i].nums);
        }
        printf("\n");

        printf("�޴��� ����� ���Թ�ȣ�� �˻��ϼ��� : ");
        scanf("%d", &select_shop);
        printf("\n");


        for (int i = 0; i < count.shop; i++) {

            if (i == select_shop - 1) {

                printf("ǰ����� �Է��ϼ��� : ");
                scanf("%s", menu[select_shop - 1][count.menu[select_shop - 1]].menu_index);
                printf("�޴����� �Է��ϼ��� : ");
                scanf("%s", menu[select_shop - 1][count.menu[select_shop - 1]].menu_name);
                printf("������ �Է��ϼ��� : ");
                scanf("%d", &menu[select_shop - 1][count.menu[select_shop - 1]].menu_price);

                menu[select_shop - 1][count.menu[select_shop - 1]].menu_except = EXCEPT_OFF;

                save_menu_count = select_shop - 1;

                break;
            }

            else if (i == count.shop - 1) {

                printf("�ش��ϴ� ���԰� �����ϴ�.\n");

            }
        }
    }
    else printf("\n���Ը� ���� ������ּ���.\n");

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
        puts(" ==== �޴� ���� ==== ");
        printf("\n");

        for (int i = 0; i < count.shop; i++) {

            puts("  ��ȣ       ��ȣ��       �ּ�       ��ȭ��ȣ    ");
            puts("==================================================");
            printf("%5d%15s%12s%8d-%d\n", i + 1, bas[i].name, bas[i].add, bas[i].num, bas[i].nums);

        }

        printf("\n");
        printf("�޴��� ������ ���� ��ȣ�� �Է��ϼ��� : ");
        scanf("%d", &select_shop);
        printf("\n");

        for (int i = 0; i < count.shop; i++) {
            if (i == select_shop - 1) {
                if (count.menu[select_shop - 1] < 1) {

                    printf("��ϵ� �޴��� �����ϴ�.");
                }
                else if (count.menu[select_shop - 1] < MAX_NUM) {
                    for (int j = 0; j < count.menu[select_shop - 1]; j++) {

                        if (menu[select_shop - 1][j].menu_except == 0)

                            puts("  ��ȣ       ǰ��       �޴���       ����    ");
                            puts("================================================");
                            printf("%5d%12s%14s%11d\n", j + 1, menu[select_shop - 1][j].menu_index, menu[select_shop - 1][j].menu_name, menu[select_shop - 1][j].menu_price);
                    }

                    printf("\n");
                    printf("�����ϰ� ���� �޴� ��ȣ�� �Է����ּ��� : ");
                    scanf("%d", &menu_search);
                    printf("\n");

                    printf("�޴� ǰ���� �Է����ּ��� : ");
                    scanf("%s", modify_index);
                    strcpy(menu[select_shop - 1][menu_search - 1].menu_index, modify_index);

                    printf("�޴� �̸��� �Է����ּ��� : ");
                    scanf("%s", modify_name);
                    strcpy(menu[select_shop - 1][menu_search - 1].menu_name, modify_name);

                    printf("�޴� ������ �Է����ּ��� : ");
                    scanf("%d", &modify_price);
                    menu[select_shop - 1][menu_search - 1].menu_price = modify_price;

                }
            }

            else if (i == count.shop - 1) {

                printf("�ش��ϴ� ���԰� �����ϴ�.\n");
            }
        }

    }

    else printf("\n���Ը� ���� ������ּ���.\n");

    movemenu();
}

void menudel(struct SHOP_MENU menu[][MAX_NUM], struct basic bas[], struct count count) {

    int delete_search, delete_search2;

    system("cls");

    if (count.shop > 0) {

        printf("\n");
        puts(" ==== �޴� ���� ==== ");
        printf("\n");

        for (int i = 0; i < count.shop; i++) {

            puts("  ��ȣ       ��ȣ��       �ּ�       ��ȭ��ȣ    ");
            puts("==================================================");
            printf("%5d%15s%12s%8d-%d\n", i + 1, bas[i].name, bas[i].add, bas[i].num, bas[i].nums);

        }

        printf("\n");
        printf("�޴��� ������ ���� ��ȣ�� �Է��ϼ��� : ");
        scanf("%d", &delete_search);
        printf("\n");
        for (int i = 0; i < count.shop; i++) {
            if (i == delete_search - 1) {
                if (count.menu[delete_search - 1] < 1) {

                    printf("��ϵ� �޴��� �����ϴ�.");
                }
                else if (count.menu[delete_search - 1] < MAX_NUM) {
                    for (int j = 0; j < count.menu[delete_search - 1]; j++) {

                        if (menu[delete_search - 1][j].menu_except == 0)
                            puts("  ��ȣ       ǰ��       �޴���       ����    ");
                            puts("================================================");
                            printf("%5d%12s%14s%11d\n", j + 1, menu[delete_search - 1][j].menu_index, menu[delete_search - 1][j].menu_name, menu[delete_search - 1][j].menu_price);

                    }

                    printf("\n");
                    printf("�����ϰ� ���� �޴� ��ȣ�� �Է����ּ��� : ");
                    scanf("%d", &delete_search2);
                    printf("\n");

                    menu[delete_search - 1][delete_search2 - 1].menu_except = EXCEPT_ON;
                }
            }

            else if (i == count.shop - 1) {

                printf("�ش��ϴ� ���԰� �����ϴ�.\n");

            }
        }
    }
    else printf("\n���Ը� ���� ������ּ���.\n");

    movemenu();
}
void menurecovery(struct SHOP_MENU menu[][MAX_NUM], struct basic bas[], struct count count) {

    int backup_num, backup_search, backup_search2;
  

    system("cls");

    if (count.shop > 0) {

        printf("\n");
        puts(" ==== �޴� ���� ==== ");
        printf("\n");

        for (int i = 0; i < count.shop; i++) {

            puts("  ��ȣ       ��ȣ��       �ּ�       ��ȭ��ȣ    ");
            puts("==================================================");
            printf("%5d%15s%12s%8d-%d\n", i + 1, bas[i].name, bas[i].add, bas[i].num, bas[i].nums);

        }

        printf("\n");
        printf("�޴��� ������ ���� ��ȣ�� �Է��ϼ��� : ");
        scanf("%d", &backup_search);
        printf("\n");
        for (int i = 0; i < count.shop; i++) {
            if (i == backup_search - 1) {
                if (count.menu[backup_search - 1] < 1) {

                    printf("��ϵ� �޴��� �����ϴ�.");
                }
                else if (count.menu[backup_search - 1] < MAX_NUM) {
                    printf(" \n == ���� �� �׸� == \n\n");
                    for (int j = 0; j < count.menu[backup_search - 1]; j++) {

                        if (menu[backup_search - 1][j].menu_except == 1)
                            puts("  ��ȣ       ǰ��       �޴���       ����    ");
                            puts("================================================");
                            printf("%5d%12s%14s%11d\n", j + 1, menu[backup_search - 1][j].menu_index, menu[backup_search - 1][j].menu_name, menu[backup_search - 1][j].menu_price);
                    }

                    printf("\n");
                    printf("�����ϰ� ���� �޴� ��ȣ�� �Է����ּ��� : ");
                    scanf("%d", &backup_search2);

                    printf("\n");

                    menu[backup_search - 1][backup_search2 - 1].menu_except = EXCEPT_OFF;
                }
            }
            else if (i == count.shop - 1) {

                printf("�ش��ϴ� ���԰� �����ϴ�.\n");

            }
        }

    }
    
    else printf("\n���Ը� ���� ������ּ���.\n");

    movemenu();
}

//�� �Է�
void Customer_add(customer customer[], struct count count)
{
    char name1[10], call[20], address[100];
    customer[count.customer].del = 0;
    system("cls");
    printf("   <�����������>   \n\n");
    printf("����� �̸��� �Է����ּ���: ");
    gets(customer[count.customer].name);
    printf("����� ��ȭ��ȣ�� �Է����ּ���: ");
    gets(customer[count.customer].phone);
    printf("����� �ּҸ� �Է����ּ���: ");
    gets(customer[count.customer].address);
    printf("����� ������ �ԷµǾ����ϴ�.\n");

    movemenu();
}

//�� ������Ʈ
void Customer_update(customer customer[], struct count count)
{
    int choice = 0, number = 0;
    char name[10], name1[10], call[20], address[100];
    while (1)
    {
        if (count.customer == 0) //��ϵ� ���� �Ѹ� ���� ��
        {
            printf("��ϵ� ���� �Ѹ� �����ϴ�.\n");
        }
        else
        { //��ϵ� ���� ���� ��� 
            printf("�����Ϸ��� ����ȣ�� �Է����ּ���: ");
            scanf("%d%*c", &number);
            for (int i = 0; i < count.customer; i++)
            {
                if (i == number) //ã�� ���� ���� ���
                {
                    if (customer[i].del == 1)
                    {
                        printf("�̹� ������ ���Դϴ�.\n");
                        break;
                    }
                    else
                    {
                        printf("��ȣ   �̸�      ��ȭ��ȣ      �ּ�\n");
                        printf("----------------------------------------------------------------\n");
                        printf("%3d %10s %18s %18s\n", i, customer[i].name, customer[i].phone, customer[i].address);
                        Customer_print_category2();
                        while (1)
                        {
                            choice = Customer_Select(choice);
                            switch (choice)
                            {
                            case 1:
                                printf("������ �̸��� �Է����ּ���: ");
                                scanf("%s", name1);
                                strcpy(customer[i].name, name1);
                                printf("�̸��� %s���� �����Ǿ����ϴ�.\n\n", customer[i].name);
                                break;
                            case 2:
                                printf("������ ��ȭ��ȣ�� �Է����ּ���: ");
                                scanf("%s", call);
                                strcpy(customer[i].phone, call);
                                printf("��ȭ��ȣ�� %s���� �����Ǿ����ϴ�.\n\n", customer[i].phone);
                                break;
                            case 3:
                                printf("������ �ּҸ� �Է����ּ���: ");
                                gets(address);
                                strcpy(customer[i].address, address);
                                printf("�ּҰ� %s���� �����Ǿ����ϴ�.\n\n", customer[i].address);
                                break;
                            default:
                                printf("1~3������ ���ڸ� �Է����ּ���\n");
                                break;
                            }
                            break;
                        }
                    }
                    break;
                }
                else if (i == count.customer - 1) //�� ã�ƺ��� ������� 
                {
                    printf("�ش��ϴ� ���� �����ϴ�. \n");
                    break;
                }
            }
        }
        movemenu();
        break;
    }
}

//�� ���
void Customer_look(customer customer[], struct count count)
{
    int choice = 0, count1 = 0, count2 = 0;
    char name[20];
    system("cls");
    while (1)
    {
        if (count.customer == 0) //��ϵ� ���� �Ѹ� ���� ��
        {
            printf("��ϵ� ���� �Ѹ� �����ϴ�.\n");
            break;
        }
        else
        { //��ϵ� ���� ���� ��� 
            printf("��� ���� ����Ͻ÷��� 1�� �Է��Ͻðų�\n");
            printf("ã���÷��� ������ �Է����ּ���: ");
            scanf("%s%*c", name);
            if (!strcmp("1", name))
            {
                Customer_all_look(customer, count);
                count1 = Found_IT;
            }
            for (int i = 0; i < count.customer; i++)
            {
                if (!strcmp(customer[i].name, name)) //ã�� ���� ���� ���
                {
                    if (customer[i].del == 1)
                    {
                        printf("�̹� ������ ���Դϴ�.\n");
                        count1 = Found_IT;
                    }
                    else
                    {
                        if (count2 == 0)
                        {
                            printf("%s�� �ش��ϴ� ���� ã�ҽ��ϴ�.\n", name);
                            printf("��ȣ   �̸�      ��ȭ��ȣ      �ּ�\n");
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
                else if (i == count.customer - 1 && count1 != Found_IT) //�� ã�ƺ��� ������� 
                {
                    printf("%s�� �ش��ϴ� ���� �����ϴ�. \n", name);
                }
            }
        }
        movemenu();
        break;
    }
}

//�� ����
void Customer_delete(customer customer[], struct count count)
{
    int choice = 0, number = 0, count1 = 0;;
    char name[10];
    char name2[10];
    while (1)
    {
        if (count.customer == 0) //��ϵ� ���� �Ѹ� ���� ��
        {
            printf("��ϵ� ���� �Ѹ� �����ϴ�.\n");
        }
        else
        { //��ϵ� ���� ���� ��� 
            printf("������ ��� ���� ����Ͻ÷��� s�� �Է��Ͻðų�\n");
            printf("�����Ͻ÷��� ����ȣ�� �Է����ּ���: ");
            scanf("%s%*c", name);
            if (!strcmp("s", name))
            {
                Customer_delete_all_look(customer, count);
                count1 = Found_IT;

            }
            for (int i = 0; i < count.customer; i++)
            {
                if (i == atoi(name) && Customer_check(name) == 0) //ã�� ���� ���� ���
                {
                    if (customer[i].del == 1)
                    {
                        printf("�̹� ������ ���Դϴ�.\n");
                        count1 == Found_IT;
                    }
                    else
                    {
                        printf("%s�� �ش��ϴ� ���� ã�ҽ��ϴ�.\n", customer[i].name);
                        printf("��ȣ   �̸�      ��ȭ��ȣ      �ּ�\n");
                        printf("----------------------------------------------------------------\n");
                        printf("%3d %10s %18s %18s\n", i, customer[i].name, customer[i].phone, customer[i].address);
                        printf("������ �����Ͻðڽ��ϱ�?\n");
                        printf("�����Ͻ÷��� ���̸��� �Է����ּ���: ");
                        scanf("%s", name2);
                        if (!strcmp(customer[i].name, name2)) //�Է��ؼ� ���� ��� 
                        {
                            customer[i].del = 1;
                            printf("%s ���� �����Ǿ����ϴ�.\n", customer[i].name);
                            count1 == Found_IT;
                        }
                        else
                        {
                            printf("�����Ϸ��� ������ Ʋ���ϴ�.\n");
                            count1 == Found_IT;
                        }
                    }
                    break;
                }
                else if (i == count.customer - 1 && count1 != Found_IT) //�� ã�ƺ��� ������� 
                {
                    printf("�ش��ϴ� ���� �����ϴ�. \n");
                    break;
                }
            }
        }
        movemenu();
        break;

    }
}

//�� ����
void Customer_recovery(customer customer[], struct count count)
{
    int choice = 0, number = 0, count1 = 0;
    char name[10];
    char name2[10];
    while (1)
    {
        if (count.customer == 0) //��ϵ� ���� �Ѹ� ���� ��
        {
            printf("��ϵ� ���� �Ѹ� �����ϴ�.\n");
            count1 == Found_IT;
        }
        else
        { //��ϵ� ���� ���� ��� 
            printf("�����Ϸ��� ����ȣ�� �Է����ּ���: ");
            scanf("%d", &number);
            for (int i = 0; i < count.customer; i++)
            {
                if (i == number)
                {
                    if (customer[i].del == 0)
                    {
                        printf("������ ȸ���� �ƴմϴ�.\n");
                    }
                    else
                    {
                        printf("������ �� %s�� ã�ҽ��ϴ�.\n", customer[i].name);
                        printf("��ȣ   �̸�      ��ȭ��ȣ      �ּ�\n");
                        printf("----------------------------------------------------------------\n");
                        printf("%3d %10s %18s %18s\n", i, customer[i].name, customer[i].phone, customer[i].address);
                        printf("�����Ͻ÷��� �̸��� �ٽ� �Է����ּ���: ");
                        scanf("%s%*c", name2);
                        if (!strcmp(customer[i].name, name2)) //�ٽ��Է��ؼ� ���� ��� 
                        {
                            customer[i].del = 0;
                            printf("%s ���� �����Ǿ����ϴ�.\n", customer[i].name);
                            count1 = Found_IT;
                        }
                        else
                        {
                            printf("�����Ϸ��� ������ Ʋ���ϴ�.\n");
                            count1 = Found_IT;
                        }
                    }
                }
                else if (i == count.customer - 1 && count1 != Found_IT) //�� ã�ƺ��� ������� 
                {
                    printf("�����Ϸ��� ���� ã������ �����ϴ�. \n");
                }
            }
        }
        movemenu();
        break;
    }
}

//�� update ī�װ� 
void Customer_print_category2() {
    printf("(1) �̸� ���� \n");
    printf("(2) ��ȭ��ȣ ���� \n");
    printf("(3) �ּҺ��� \n");
}

//����ġ�� ���� 
int Customer_Select(int choice)
{
    printf("�׸��� �������ּ���: ");
    scanf("%d%*c", &choice);
    return choice;
}

//�� ��ü ��� 
void Customer_all_look(customer customer[], struct count count)
{
    printf("��ȣ   �̸�      ��ȭ��ȣ      �ּ�\n");
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

//������ �� ��ü ��� 
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
        printf("��ȣ   �̸�      ��ȭ��ȣ      �ּ�\n");
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
        printf("������ ���� �Ѹ� �����ϴ�.\n");
}

//�׽�Ʈ ������
void testdata(customer customer[])
{
    strcpy(customer[0].name, "����");
    strcpy(customer[0].phone, "010-2352-7813");
    strcpy(customer[0].address, "��õ��");
    customer[0].del = 0;

    strcpy(customer[1].name, "���ñ��");
    strcpy(customer[1].phone, "010-3209-1557");
    strcpy(customer[1].address, "�뿬��");
    customer[1].del = 0;
}

//�������� üũ
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
    //���� ������
    if (count.shop == 0)
    {
        printf("��ϵ� ���԰� �����ϴ�. ���߿� �ٽ� �õ����ּ���");
    }
    //���� ���� ��� 
    else
    {
        printf("\n");
        puts(" ============== ���� ��� ============== ");
        printf("\n");
        //�ִ� ���� ������ְ�(�����Ȱ� ���� ��� �ȵ�)
        for (int i = 0; i < count.shop; i++) {

            puts("  ��ȣ       ��ȣ��       �ּ�       ��ȭ��ȣ    ");
            puts("==================================================");
            printf("%5d%15s%12s%8d-%d\n", i + 1, bas[i].name, bas[i].add, bas[i].num, bas[i].nums);

        }
        //���� ��ȣ ���� 
        printf("\n");
        printf("�ֹ��� ���Թ�ȣ�� �Է��ϼ��� : ");
        scanf("%d", &select_shop);
        printf("\n");
        //���� ��ȣ �ִ��� Ȯ�� 
        for (int i = 0; i < count.shop; i++)
        {
            //�������� ���
            if (bas[count.shop - 1].del == 1)
            {
                printf("������ �����Դϴ�.\n");
                count1 = Found_IT;

            }
            //�ִ°����� ��� 
            else if (select_shop - 1 == i)
            {
                //�޴��� ������� 
                if (count.menu[select_shop - 1] < 1)
                {
                    printf("��ϵ� �޴��� �����ϴ�.");
                    count1 = Found_IT;
                }

                //���Կ� �޴��� ������� ���
                else if (count.menu[select_shop - 1] < MAX_NUM)
                {
                    for (int j = 0; j < count.menu[select_shop - 1]; j++)
                    {
                        //������ �޴��� �ƴҰ�� 
                        if (menu[select_shop - 1][j].menu_except == 0)
                            puts("  ��ȣ       ǰ��       �޴���       ����    ");
                            puts("================================================");
                            printf("%5d%12s%14s%11d\n", j + 1, menu[select_shop - 1][j].menu_index, menu[select_shop - 1][j].menu_name, menu[select_shop - 1][j].menu_price);
                    }
                    printf("\n");
                    printf("�ֹ� �ϰ� ���� �޴� ��ȣ�� �Է����ּ��� : ");
                    scanf("%d", &menu_search);
                    for (int k = 0; k < count.menu[select_shop - 1]; k++)
                    {
                        if (menu_search - 1 == k)
                        {
                            printf("\n");
                            printf("%s �޴��� �ֹ� �Ϸ� �Ǿ����ϴ�.\n ", menu[select_shop - 1][menu_search - 1].menu_name);
                            printf("\n");
                            puts(" ����������������������������������������������������������������������������������������������������������������������������");
                            puts(" ��                                                            ��");
                            puts(" ��                                                            ��");
                            puts(" �� ====================== < �� �� �� > =======================��");
                            puts(" ��                                                            ��");
                            puts(" ��                                                            ��");
                            printf(" ��  ��ȣ�� : %5s   ��ȭ��ȣ : %5d-%d   �ּ� : %5s ��\n", bas[select_shop - 1].name, bas[select_shop - 1].num, bas[select_shop - 1].nums, bas[select_shop - 1].add);
                            puts(" ��                                                            ��");
                            puts(" ��                                                            ��");
                            printf(" ��        �ֹ��޴� : %5s       ���� : %5d��            ��\n", menu[select_shop - 1][menu_search - 1].menu_name, menu[select_shop - 1][menu_search - 1].menu_price);
                            puts(" ��                                                            ��");
                            puts(" ��                                                            ��");
                            puts(" �� ===========================================================��");
                            puts(" ��                                                            ��");
                            puts(" ��                                                            ��");
                            puts(" ����������������������������������������������������������������������������������������������������������������������������");
                            count2 = Found_IT;
                        }
                        else if (k == count.menu[select_shop - 1] - 1 && count2 != Found_IT)
                            printf("���� ��ȣ�� �Է��߽��ϴ�. �ٽ� �Է����ּ���.");
                    }
                }
                count1 = Found_IT;
            }
            //���� ������ ���
            else if (i == count.shop - 1 && count1 != Found_IT)
            {
                printf("���Թ�ȣ�� ����� �Է����ּ���\n");
            }
        }
    }

    movemenu();
}