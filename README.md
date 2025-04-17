# Simulador de Sistema Operacional

Alunos
- Diogo Buzatto – RA: 111809  
- Lucas Ferreira – RA: 111519  
- Mauricio Sarpa – RA: 112824  
- Pablo Novais Ramos – RA: 112070  

## 1. Introdução

Este trabalho apresenta um simulador de Sistema Operacional desenvolvido em C++ com ênfase na aplicação prática de conceitos fundamentais da disciplina, como gerenciamento de processos e memória. O projeto utiliza os princípios da programação orientada a objetos para estruturar os principais componentes do sistema.

## 2. Objetivos

- Simular o funcionamento básico de um sistema operacional;
- Aplicar conceitos de orientação a objetos (herança, encapsulamento e polimorfismo);
- Analisar o comportamento do sistema com diferentes estratégias de escalonamento e alocação de memória.

## 3. Fundamentação Teórica

A simulação é baseada nos conceitos descritos por autores como Tanenbaum (2015) e Silberschatz et al. (2018):

- Gerenciamento de Processos: Controle da criação, execução e finalização de processos com diferentes prioridades, tempos de execução e chegada.
- Escalonamento: Implementados dois algoritmos clássicos: Round Robin (com quantum configurável) e Prioridade.
- Gerenciamento de Memória: Suporte à alocação via partições fixas e memória paginada, permitindo comparar a eficiência e fragmentação de cada abordagem.

## 4. Desenvolvimento

O sistema é modular, com componentes principais:

- Processo: Contém PID, prioridade, tempo de chegada, execução, e estado atual.
- Escalonadores: 
  - Round Robin: tempo de CPU fixo por processo (quantum).
  - Prioridade: seleciona o processo pronto com menor valor de prioridade.
- Gerenciadores de Memória:
  - Partições Fixas: memória dividida em blocos de tamanho fixo.
  - Paginada: memória dividida em páginas, com alocação dinâmica.
- Sistema Operacional: Instancia e gerencia os componentes, executa os ciclos de simulação e exibe o resumo final.

## 5. Resultados

A simulação é interativa via terminal, com as seguintes etapas:

1. Criação de processos (aleatórios).
2. Escolha do tipo de escalonador e memória.
3. Execução da simulação:
   - Processos são alocados, executados e finalizados.
   - Estado dos processos atualizado conforme execução.
   - Liberação de memória ao final.
4. Exibição de resumo com tempo total e memória disponível.

6. Conclusão

O projeto contribuiu significativamente para a compreensão prática dos conceitos de sistemas operacionais. Foi possível observar de forma concreta como o gerenciamento de memória e escalonamento afetam o desempenho do sistema. Além disso, o uso da linguagem C++ reforçou habilidades de programação orientada a objetos e manipulação de ponteiros.

## 7. Melhorias Futuras

- Usar tempos de chegada progressivos para processos.
- Calcular métricas por processo: tempo de espera, turnaround, tempo de CPU utilizado.
- Criar interface gráfica para visualização dos estados e da memória.

## 8. Referências

- TANENBAUM, A. S.; BOS, H. Modern Operating Systems. 4. ed. Pearson, 2015.  
- SILBERSCHATZ, A.; GALVIN, P. B.; GAGNE, G. Operating System Concepts. 10. ed. Wiley, 2018.
