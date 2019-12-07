# PRO-SOL 
![solzinho](https://user-images.githubusercontent.com/55321500/70361002-e8cd9100-185e-11ea-9199-f91a05679386.jpg)

_Projeto de cadastramento de dados destinados ao comissionamento solar fotovoltaico, utilizando  o QT creator, para a disciplina de Técnicas de Programação 2019.2._

        Objetivos
Destinar um projeto para: 
  - O cálculo de números de módulos utilizados em um sistema "x";
  - O cálculo da potência destinada ao projeto solar fotovoltaico;
  - Controle dos sistemas na qual já foram realizados.

## Manual do Programa *Pro-Sol*

### Como usar o programa?

A interface do programa traz de uma forma simples o cadastramento de três variáveis fundamentais para elaboração do projeto fotovoltaico.

1. Para a inicialização do projeto trás o **nome do cliente** como pré-requisito base, pois é através do mesmo que é efetuado a solicitação do projeto na concessionária, por meio da RT.

![FATURA](https://user-images.githubusercontent.com/55321500/70357036-a43cf800-1854-11ea-9f04-bea4e52e0a18.JPG)

2. A **Unidade Consumidora** é a matrícula destinado ao medidor de cada cliente, sendo assim, é a partir dele que é realizado todo o trâmite entre a concessionária e o sistema fotovoltaico solicitado.

3. Por fim, Inserimos o **consumo médio** da UC , que parametriza a potência do sistema e a quantidade de módulos necessários para suprir o consumo na qual foi projetado.

O cálculo da **Potência** é feito através da variável consumo, sendo assim, atribuindo a quantidade do **número de módulos** pelo o cálculo da potência.

|Calculo da Potência|Cálculo do número de módulos  |
| -|--|
|  Potência = (consumo)/130;|  N° de módulos =  (potencia*1000)/335;   |


	interface do programa

![interface](https://user-images.githubusercontent.com/55321500/70379075-1837d880-1907-11ea-93d9-2238514cd591.JPG)


### Organização por Cliente Cadastrado
Inicialmente, produzimos uma função que ordena por nome do cliente cadastrado, na qual está inserida dentro da classe ***Projeto.h*** (a classe formada por um vetor de projetos cadastrados).
```
void Projeto::ordenarPorCliente()
{
    std::sort(projetoSolar.begin(), projetoSolar.end(), [](Consumidor t, Consumidor v){return t.getNome()< v.getNome();});
}
```
A biblioteca <Algorithm> foi usada para ordenar através da função **sort**.
Logo em seguida, definimos a função na MAINWINDOWN.H, declarando da seguinte forma.

```
void MainWindow::on_ordenarNome_clicked()
{
    ui->tbl_in->clearContents();

    microgeracao.ordenarPorCliente();

    for(int i = 0; i < microgeracao.size();i++){
        inserirNaTabela(microgeracao[i],i);
    }
}
```


### Organização por Consumo(kWh)
A organização por Consumo se assemelha a feita por Cliente, de forma que utilizamos a função **sort** para ordenar.

```sh
void Projeto::ordenarPorConsumo()
{
    std::sort(projetoSolar.begin(),projetoSolar.end(), [](Consumidor n,Consumidor m){return n.getConsumo() < m.getConsumo()
                ;});
}
```

### Salvando e Carregando um arquivo
Para salvar e carregar no *Pro-sol*, o acesso é feito pelo o menu localizado na aba superior do programa, de forma que o usuário tenha a possibilidade de acessar um arquivo já pronto.

![menu_projeto](https://user-images.githubusercontent.com/55321500/70379038-ba0af580-1906-11ea-9c9e-b0092b07988f.JPG)

Mostrando uma caixa de mensagem quando for lido corretamente

![arquivo_n_lido](https://user-images.githubusercontent.com/55321500/70380833-19293400-1920-11ea-9018-cec30db40997.JPG)

E quando o arquivo não for salvo, o programa enviará a mensagem de erro ao usuário.
![arquivo_n_salvo](https://user-images.githubusercontent.com/55321500/70379155-ad3ad180-1907-11ea-8d2f-d2b5d16b0084.JPG)


### Estatísticas 
Para a visualização da quantidade de projetos cadastrados, selecionamos a aba *estatísticas*. 

![estastisticas_projeto](https://user-images.githubusercontent.com/55321500/70379970-fb090700-1912-11ea-9d85-d531f6930c2a.JPG)

Trazendo de uma forma simples, o controle de dados. 

### E para editar os dados já cadastrados?

Simples!! 
Basta clicar na tabela, que de uma forma interativa, aparecerá a caixa de edição, permitindo ao usuário fazer a correção da variável escolhida.

1°) Passo
![deseja editar item](https://user-images.githubusercontent.com/55321500/70380912-33afdd00-1921-11ea-9846-bd5df7beaa15.JPG)


2°)Passo![noovo objeto](https://user-images.githubusercontent.com/55321500/70380920-52ae6f00-1921-11ea-94bf-702a1b9fe6c8.JPG)

						          !PRONTO!
			  Agora só falta você testar e dá o seu feedback
						        
Contatos:
Email: taynara.lopes@academico.ifpb.edu.br
Instagram: taylope| [enter link description here](https://www.instagram.com/taylope/?hl=pt-br)
