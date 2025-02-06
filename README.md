# 🚀 LEDCountDown [Vídeo de apresentação](https://youtu.be/eI9AtzHlC2U)

🔗 **Repositório:** [LEDCountDown](https://github.com/CarlosValadao/LEDCountDown)

O **LEDCountDown** é um programa desenvolvido para a **Raspberry Pi Pico**, que utiliza um botão para acionar três LEDs (**verde, vermelho e azul**). Após a ativação, os LEDs vão **apagando um a um a cada 3 segundos**, utilizando um **alarme one-shot**.

## 🚀 Requisitos

O código foi desenvolvido e testado na **Plataforma BitDogLab** versão 6.3, com os seguintes requisitos:

- 🛒 **Raspberry Pi Pico**
- 🔧 **BitDogLab** versão 6.3
- 💻 **Linguagem C** (Versão 11)
- 🛠️ **Pico SDK** (Versão 2.1.0)
- 🔧 **VS Code** com extensões **CMake**, **Raspberry Pi Pico** e **Wokwi**
- ⚙️ **Compilador:** **GNU ARM Embedded Toolchain** (`gcc-arm-eabi`)

## 🧑‍💻 Funcionalidades

1. 🔘 **Botão principal** ativa os **três LEDs (verde, vermelho e azul)**.
2. ⏱️ O **tempo de acionamento** do botão não afeta o comportamento do LED.
3. 🔄 Após **3 segundos**, um LED se apaga até que todos estejam desligados.
4. 🕒 **Utiliza um alarme one-shot** para controlar o tempo de apagamento.
5. 🚨 **Gerenciamento do debounce** para evitar leituras falsas do botão.

## 🧩 Componentes

- 🟢 **LED Verde**
- 🔴 **LED Vermelho**
- 🔵 **LED Azul**
- 🔘 **Botão de acionamento**

## ⚙️ Como Funciona

1. O botão é pressionado, e todos os LEDs **acendem simultaneamente**.
2. Um **alarme one-shot** é ativado e, **a cada 3 segundos**, um LED é apagado.
3. Quando **todos os LEDs são apagados**, o sistema aguarda uma nova ativação.

## 🛠️ Instalação

### 1️⃣ Clonar o repositório

```bash
git clone https://github.com/CarlosValadao/LEDCountDown.git
cd LEDCountDown
```

### 2️⃣ Instalar dependências

Certifique-se de ter instalado:

- 🛠️ **pico-sdk** (versão 2.1.0)
- ⚙️ **GCC ARM Embedded Toolchain (gcc-arm-eabi)**
- 🔧 **CMake**
- 🏗️ **Ninja** (opcional, mas recomendado)

### 3️⃣ Compilar o projeto

```bash
mkdir build
cd build
cmake ..
make
```

Isso gerará o arquivo **.uf2** que pode ser carregado na **Raspberry Pi Pico**.

## ▶️ Executando o Programa

1. **Entre no modo bootloader**
   - Pressione o botão **BOOTSEL** da Raspberry Pi Pico e conecte-a ao PC via **USB**.
   - Solte o botão após a conexão.

2. **Carregar o firmware**
   - Copie o arquivo **.uf2** gerado na pasta `build/` para a unidade que aparece no sistema (geralmente `RPI-RP2`).

## 🔬 Simulação com Wokwi

Este projeto **pode ser simulado** no [Wokwi](https://wokwi.com/), pois contém os arquivos `diagram.json` e `wokwi.toml`.

### 📌 Para rodar no Wokwi via **VS Code**

1. Abra o projeto no **VS Code**.
2. Clique no botão **Run Wokwi Simulation**.
3. Visualize a simulação diretamente no editor.


## 📜 Licença

Este projeto está licenciado sob a **MIT License**.

## 💬 Contribuição

Sinta-se à vontade para abrir *issues* e *pull requests* para melhorias ou correções.

---

**Carlos Valadao**  
📅 **Data:** 04/02/2025
