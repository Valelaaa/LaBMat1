// MatLab01.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include "MSlab.h"
int main()
{
	setlocale(LC_ALL, "RUSSIAN");	//Русский язык в Студию ...вижуал студию
	int option;				//вариант
	int variant;			//...тоже вариант
	bool var1=false, var2=false, var3=false;	//...И это вариант
	int** Inc=NULL;			//Матрица иници..Инициди..Инци..Короче компания Inc.
	int** Adj=NULL;			//ajencicy? adjenecy?...Почему так сложно? 
	vector<vector<int>> Adl;	//Просто красивый цвет
	int n=0, m=0;		//P.S. no money
	do 
	{
		system("cls");				//Начнем с чистого листа
		Menu();					//Вы готовы сделать заказ?
		cin >> option;
		if (option<0 || option>4)	 //Ни больше, ни меньше
		{
			cout << "Ты совершил большую ошибку ";  //Не надо так
			loading(4, 0.25);					//Одну секундочку
			return(23);
		}
		if (option == 1)			//1st variant Ввод
		{
			system("cls");			//Складываем весь хлам под кровать
			cout << "{ Ввод }:" << endl;	//Ввод...Неожиданно, правда?
			Choice();				//Пёрфект инглиш
			cin >> variant;			
			switch (variant)		//TellTle games представляет
			{
				case (1):			//Дело 1
				{
					if (var1 || var3 || var2)		//Не стоит повторяться
					{
						cout << "Вы уже ввели одну матрицу";	//Ну правда, одной достаточно
					}
					else
					{
						cout << "Ввод матрицы Инцидентности:" << endl;	
						cout << "Вершины: "; cin >> m;			
						cout << "Ребра: "; cin >> n;				
						if (m < 0 || m>50 || n<0 || n>50)		//Слишком много(мало) информации
						{
							return(47);
						}
						Incidence_input(Inc, n, m);			//InPut -> Inc - Putin Incorporation
						cout << "Матрица введена успешно"; loading(3, 0.3);
						var1 = true;			//Флаг?
					}					
					break;			//Ломай его!!
				}
				case(2):			//Дело #2
				{
					if (var1 || var3 || var2)		//Не стоит повторяться 
					{
						cout << "Одна матрица уже введена" << endl;		//Ну правда, хватит уже
					}
					else
					{
						cout << "Ввод матрицы Смежности:" << endl;
						cout << "Вершины: "; cin >> m;
						if (m < 0 || m>50)		//Ничего нового
						{
							return(67);
						}
						Adjacency_input(Adj, m);
						cout << "Ввод произведен успешно"; loading(3, 0.3);
						var2 = true;	//Повторение - мать учения... но не в этом случае.
					}					
					break;
				}
				case(3):			//Следствие #3
				{
					if (var1 || var3 || var2)		//Дежавю? Не стоит повторяться 
					{
						cout << "Одной матрицы достаточно" << endl;
					}
					else
					{
						cout << "Ввод списка Смежности:" << endl;  //А ты точно матрица?
						cout << "Вершины: "; cin >> m;
						Adl = Adjacency_list_input(m);
						cout << "Список смежности сформирован"; loading(3, 0.3);
						var3 = true;	//Ложь, повторенная тысячу раз, становится правдой!
					}
					break;
				}
				case(4):  //4тое деяние
				{
					cout << "Yes my Lady"; loading(3, 0.33); //Yes, my Lord
					break;
				}
			}
		}
		else if (option == 2)	
		{
			system("cls");				//Убираем творческий беспорядок
			cout << "{ Вывод }:" << endl;
			Choice();
			cin >> variant;
			switch (variant)	//Он это запомнит
			{
			case 1: //бой 1
			{
				if (var1) 
				{
					cout << "Матрица инцидентности:" << endl;	//Вывод
					Incidence_print(Inc, n, m);
					system("pause");							//Пауза
				}
				else if (var2) 
				{
					cout << "Матрица инцидентности:" << endl;	//solo leveling top
					Adl = Adjacency_to_list(Adj, m);		//Adj mat ->adj list
					Inc = List_to_invidence(Adl, n, m);		//adj list -> inc mat
					Incidence_print(Inc, n, m);
					system("pause");
				}
				else if (var3)
				{
					cout << "Матрица инцидентности:" << endl;	
					Inc = List_to_invidence(Adl, n, m);			//adj list -> inc mat
					Incidence_print(Inc, n, m);
					system("pause");
				}
				else if (!var1 || !var3 || !var2)
				{											//Oshihete oshihete yo
					cout << "Сначала ввод, потом вывод"; loading(3, 2);		//sono shikumi wo
					break;										//boku no naka ni
				}												//Dare ga iru no
				break;											//kowareta kowareta yo
			}											//kono sekai de
			case 2:			//Эпизод 2					//kimi ga warau
			{											//nanimo miezu ni
				if (var1)						//КХМ КХМ.. Просто музыка в наушниках заиграла..
				{
					Adj = Incidence_to_Adjacency(Inc, n, m);	//Inc -> adj mat
					Adjacency_print(Adj, m);
					system("pause");
				}
				else if (var2)
				{
					Adjacency_print(Adj, m);
					system("pause");
				}
				else if (var3)
				{
					Inc = List_to_invidence(Adl, n, m);		//adj list -> inc mat
					Adj = Incidence_to_Adjacency(Inc, n, m);	//Inc -> adj mat
					Adjacency_print(Adj, m);
					system("pause");
				}
				else if (!var1 || !var3 || !var2)
				{
					cout << "Начинать нужно с малого...С ввода!"; loading(3, 2); //Я бы прислушался
					break;
				}
				break;
			}
			case 3: //3тья часть
			{
				if (var1) 
				{
					Adj = Incidence_to_Adjacency(Inc, n, m);	//Inc -> adj mat
					Adl = Adjacency_to_list(Adj, m);		//Adj mat ->adj list
					Adjacency_list_print(Adl);
					system("pause");
				}
				if (var2)
				{
					Adl = Adjacency_to_list(Adj, m);		//Adj mat ->adj list
					Adjacency_list_print(Adl);
					system("pause");
				}
				if (var3) 
				{
					Adjacency_list_print(Adl);
					system("pause");
				}
				else if (!var1 || !var3 || !var2)
				{
					cout << "Подсказочка - scanf,cin,input.."; loading(5, 2); //Если кто не понял, 
					break;													//Массив не введен
				}
				break;
			}
			case 4: //4тый сезон 
			{
				cout << "Yes Your Highness"; loading(6, 0.33); //Yes, Your magesty
				break;
			}
			}
		}
		else if (option == 3)
		{
			var1 = false, var2 = false, var3 = false;
			cout << "RESTARTING THE PROGRAM"; loading(5, 1);	//Правильное начало — половина дела.
			continue;
		}
		else
		{
			cout << "\nПриходите к нам еще!";	//子曰、士志於道、而耻恶衣恶食者、未足与议也。
			return(0);						//Конфуций, перевод утерян 
		}
	} while (true);
	return(1);
}
//Текст,чтоб не было скучно и одиноко <3