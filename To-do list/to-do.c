#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char *task;
    int completed;
    
} Task;

Task *tasks = NULL;
int lenght = 0;

void addTask(const char *task)
{
    tasks = (Task *)realloc(tasks, (lenght + 1) * sizeof(Task));
    tasks[lenght].task = (char *)malloc(strlen(task) + 1);
    tasks[lenght].completed = 0;

    strcpy(tasks[lenght].task, task);

    lenght++;
    printf("tarefa adicionada");
}

void listTask()
{
    char status;
    for (int i = 0; i < lenght; i++)
    {
        if (tasks[i].completed == 1)
        {
            status = 'C';
        }
        else
        {
            status = 'I';
        }

        printf("%d. %s [%c]\n", i + 1, tasks[i].task, status);
    }
}

void markCompleted(int index)
{
    if (index <= lenght && index > 0)
    {
        tasks[index - 1].completed = 1;
        printf("tarefa feita com sucesso");
    }
    else
    {
        printf("indice invalido");
    }
}

void deleteTask(int index)
{

    if (index <= lenght && index > 0)
    {
        index = index - 1;

        free(tasks[index].task);

        for (int i = index; i < lenght - 1; i++)
        {
            tasks[i] = tasks[i + 1];
        }

        lenght--;

        tasks = (Task *)realloc(tasks, (lenght * sizeof(Task)));
    }
    else
    {
        printf("indice invalido");
    }
}

void editTask(int index, const char *task)
{

    if (index <= lenght && index > 0)
    {
        index = index - 1;

        char *editTask = (char *)realloc(tasks[index].task, strlen(task) + 1);

        if (editTask != NULL)
        {
            tasks[index].task = editTask;
            strcpy(tasks[index].task, task);
            printf("tarefa atualizada com sucesso");
        }
        else
        {
            printf("erro na alocação de memória");
        }
    }
}

int main()
{
    int enterTask;
    char addtask[100];
    int x = 0;

    puts("bem vindo ao seu afazer de tarefas");
comeco:
    puts("\nselecione alguma das opcoes a seguir\n------------------------------------\ndigite 1 para adicionar uma tarefa na lista\ndigite 2 para visualizar a lista de tarefas\ndigite 3 para marcar como completa\ndigite 4 para editar tarefa\ndigite 5 para remover uma tarefa da lista\ndigite 6 para sair do programa\n");
    scanf("%d\n", &x);

    if (x == 1)
    {
        puts("insira o afazer");
        getchar();
        fgets(addtask, sizeof(addtask), stdin);
        addtask[strcspn(addtask, "\n")] = '\0';
        addTask(addtask);
        goto comeco;
    }
    else if (x == 2)
    {

        listTask();

        goto comeco;
    }
    else if (x == 3)
    {

        printf("escolha a tarefa");
        scanf("%d", &enterTask);
        markCompleted(enterTask);

        goto comeco;
    }

    else if (x == 4)
    {

        printf("escolha a tarefa:");
        scanf("%d", &enterTask);
        printf("altere a tarefa:");
        getchar();
        fgets(addtask, sizeof(addtask), stdin);
        addtask[strcspn(addtask, "\n")] = '\0';

        editTask(enterTask, addtask);

        goto comeco;
    }
    else if (x == 5)
    {
        printf("escolha a tarefa:");
        scanf("%d", &enterTask);

        deleteTask(enterTask);

        goto comeco;
    } else if (x == 6){

        printf("fim do programa");

    free(tasks);
        return 0;
    }
    else
    {
        printf("valor incorreto, selecione um dos numeros 1, 2, 3, 4, 5 ou 6.\n");
        goto comeco;
    }

    
}
