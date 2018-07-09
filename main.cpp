#include <stdio.h>
#include <iostream>

using namespace std;

int main(void)
{

    int itext[658];
    int ioriginal[658];

    int raznost[658];

    int rasshifrovka1[658];
    char rasshifrovka1_s[658];

    char ABC[] = "������񦧨�����������������������";
    char text[] = "���������㢥���ॢ������������������覠��룬�����⠢�������ਠ���������桩�����殥��������������ᦣ����第�笭�����棯蠟��쩠룬���񢯬렢�壮쨭�������ꮩ�����便��婡������裡������㯨�����룬짢��藍�����觤���쪢�����檧�����������ࡣ������थ����覣���ᥢ���������楣���㯣��������񥤬���塪������订񠬢���頬�襮������񥥠��������즠�㤠����㡤���ᣢ���������᫢����������櫥����梦��������������쩥��㢣�����������嵐训����񥨮�������䯥�ꮢ����ᡯ����㮨�补�㢭�����桩����ࢭ��㧠����������쨠���䥢�������ꠣ�����";
    char original[] = "�᫨����⠥���⮮����冷��宧索���ᥬ����㤥���஥��᫨���⥡ﮫ�����������⮭���ਠ�⭠��ᠭ�殮�᪨娬�����騡�������墮�����뫠�묮�ன�᮫���ન��᫨⥡���饮���᭨�쨯�������";

    //-----------------------------------------------------------------------------

    cout << "�����   ���஢��  �����  ��������\n";

    for(int i=0; i<184; i++)
    {
        for(int j=0; j<33; j++)
        {
            if(text[i] == ABC[j])
            {
                itext[i] = j;
            }

            if(original[i] == ABC[j])
            {
                ioriginal[i] = j;
            }
        }

        raznost[i] = itext[i] - ioriginal[i];

        cout << i+1 << "   ||      " << ioriginal[i] << "       " << itext[i] << "      " << raznost[i] << "\n";
    }

    cout << "\n\n";

    //--------------------------------------------------------------------------------

    //���� ��ਠ�� ����
    for(int i=0; i<184; i++)
    {
        if(i%4 == 0)
            cout << "\n";

        if(raznost[i]<0)
            raznost[i] += 33;

        cout << raznost[i] << " ";
    }
    cout << "\n\n";
    //�뢮� ����
    int key1[4];
    for(int i=0; i<4;i++)
    {
        key1[i] = raznost[i];
        cout << ABC[(key1[i])];
    }

    cout << "\n\n";

    //-------------------------------------------------------------------------------

    //��ன ��ਠ�� ����
    for(int i=0; i<184; i++)
    {
        if(i%4 == 0)
            cout << "\n";

        if(raznost[i]>0)
        {
            raznost[i] -= 33;
            raznost[i] = abs(raznost[i]);
        }

        cout << raznost[i] << " ";
    }
    cout << "\n\n" ;
    //�뢮� ����
    int key2[4];
    for(int i=0; i<4;i++)
    {
        key2[i] = raznost[i];
        cout << ABC[(key2[i])];
    }

    //--------------------------�����஢��--------------------------------------------------------

    //���室�� ⮫쪮 ���� ����

    for(int i=0; i<658; i++)
    {
        for(int j=0; j<33; j++)
        {
            if(text[i] == ABC[j])
            {
                itext[i] = j;
            }
        }
    }

     cout << endl << rasshifrovka1_s;

    for(int i=0, j=0; i<658; i++, j++)
    {
        if(j == 4) j = 0;

        rasshifrovka1[i] = itext[i] - key1[j];

        if(rasshifrovka1[i] < 0) rasshifrovka1[i] += 33;

        rasshifrovka1_s[i] = ABC[(rasshifrovka1[i])];
    }

    //---------------------------������ � 䠩�---------------------------------------------------

    cout << endl << rasshifrovka1_s;

    FILE *f=fopen("pro.txt","w");
    if(f==NULL)
        printf("�訡�� ������ 䠩��!");
    fwrite(rasshifrovka1_s, sizeof(char), 658, f);
    fclose(f);
}

