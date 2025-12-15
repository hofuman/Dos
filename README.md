# TCP DOS (C)

> ⚠️ **Aviso legal**: Este projeto foi desenvolvido **exclusivamente para fins educacionais e de estudo** sobre programação em C e funcionamento de sockets TCP. **Não utilize este código para ataques, testes de estresse ou qualquer atividade sem autorização explícita**, pois isso pode ser ilegal.

---

## 📌 Descrição

Este projeto é um programa simples em **C** que realiza múltiplas tentativas de conexão TCP (`connect()`) para um **IP e porta específicos**, utilizando sockets.

O código cria repetidamente um socket TCP e tenta se conectar ao destino informado, exibindo no terminal o status de cada tentativa.

Ele é útil para:

* Estudo de **sockets em C**
* Compreensão do fluxo `socket → connect`
* Aprendizado sobre estruturas de rede como `sockaddr_in`

---

## 🧠 Funcionamento

1. O programa recebe dois argumentos via linha de comando:

   * **IP de destino**
   * **Porta de destino**
2. Caso os argumentos não sejam fornecidos, ele exibe a forma correta de uso.
3. Caso estejam corretos:

   * Converte a porta para inteiro
   * Define o endereço de destino (`sockaddr_in`)
   * Cria **10.000 sockets TCP** 
   * Tenta conectar cada socket ao destino
   * Exibe o resultado de cada tentativa

---

## 🧪 Exemplo de uso

```bash
./Dos 192.168.1.1 21
```

Saída esperada:

```text
Porta 21 - status [ 1 PACOTE ENVIADO!]
Porta 21 - status [ 2 PACOTE ENVIADO!]
Porta 21 - status [ 3 PACOTE ENVIADO!]
```

Ou, em caso de erro:

```text
Erro de conexão...
```

---

## ⚙️ Compilação

Utilize o **GCC** para compilar:

```bash
gcc Dos.c -o Dos
```

Depois execute:

```bash
./Dos <IP> <PORTA>
```

---

## 🧩 Código-fonte

Principais bibliotecas utilizadas:

* `<stdio.h>` — Entrada e saída padrão
* `<stdlib.h>` — Conversão de tipos (`atoi`)
* `<string.h>` — Manipulação de strings
* `<unistd.h>` — Funções POSIX
* `<sys/socket.h>` — Criação de sockets
* `<arpa/inet.h>` — Conversão de endereços IP
* `<netdb.h>` — Estruturas de rede

---

## 🚨 Observações importantes

* O código **não fecha os sockets** (`close()`), o que pode causar consumo excessivo de recursos.
* Não há controle de erros detalhado para `socket()`.
* O número de pacotes está fixo em **10.000**.

Esses pontos podem (e devem) ser melhorados para fins de aprendizado.

---

## 🔐 Uso responsável

Este código **não deve ser utilizado** para:

* Ataques de negação de serviço (DoS)
* Flood de conexões
* Testes em sistemas sem permissão

Use apenas em:

* Ambientes de laboratório
* Máquinas próprias
* Estudos acadêmicos

---

## 📚 Próximos aprimoramentos (sugestões)

* Fechar o socket após cada conexão (`close(meusocket)`)
* Adicionar `sleep()` para controle de taxa
* Permitir definir o número de pacotes via argumento
* Melhorar mensagens de erro com `perror()`

---

## 🧑‍💻 Autor

Desenvolvido para fins de estudo em **Programação em C e Segurança da Informação**.
Projeto DESEC
---

⭐ Se este projeto te ajudou a entender melhor sockets em C, considere deixar uma estrela no repositório!
