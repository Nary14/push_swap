

int main(int argc, char **argv)
{
    t_list  *stack;
    t_list  *tmp;
    int     i;

    stack = NULL;
    // On commence à i = 1 car argv[0] est le nom du programme
    if (argc < 2)
        return (0);
    
    i = 1;
    while (i < argc)
    {
        // Si process_number renvoie 0, il y a une erreur (doublon, pas un chiffre, overflow)
        if (!process_number(argv[i], &stack))
        {
            // Ici, il faudrait idéalement libérer la mémoire de la stack avant de quitter
            error_exit();
        }
        i++;
    }

    // --- Affichage pour vérifier le résultat ---
    printf("Contenu de la stack :\n");
    tmp = stack;
    while (tmp)
    {
        printf("%d -> ", *(int *)tmp->content);
        tmp = tmp->next;
    }
    printf("NULL\n");

    // Nettoyage de la mémoire (Optionnel pour le test, mais crucial pour le projet final)
    // ft_lstclear(&stack, free);

    return (0);
}