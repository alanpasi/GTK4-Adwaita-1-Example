# GTK4/Adwaita-1
by DeepSeek

# Project Struct

Aqui está uma sugestão de estrutura de diretórios para um projeto em C usando GTK4, com CMake/Make/GCC, organizando recursos como UI (arquivos `.ui`), estilos (CSS), cabeçalhos e código-fonte:

```
projeto-gtk4/
├── CMakeLists.txt              # Configuração principal do CMake
├── build/                     # Diretório para builds (gerado pelo cmake/make)
├── data/                      # Arquivos de dados (imagens, ícones, etc.)
│   ├── icons/                 # Ícones do aplicativo (SVG/PNG)
│   └── images/                # Outras imagens
├── docs/                      # Documentação (opcional)
├── include/                   # Cabeçalhos públicos (.h)
│   └── app/                   # Cabeçalhos específicos do projeto
│       ├── window.h           # Exemplo: cabeçalho da janela principal
│       └── config.h           # Configurações/definições
├── src/                       # Código-fonte (.c)
│   ├── main.c                 # Ponto de entrada
│   ├── window.c              # Implementação da janela
│   └── resources.c           # Arquivo gerado para recursos (GResource)
├── ui/                        # Arquivos de interface (XML .ui)
│   ├── main_window.ui         # Exemplo: janela principal (Glade/Builder)
│   └── dialogs.ui            # Diálogos
├── style/                     # Estilos CSS para GTK
│   ├── main.css              # Estilo principal
│   └── dark.css              # Tema escuro (opcional)
├── po/                        # Internacionalização (gettext)
│   ├── POTFILES.in           # Lista de arquivos com strings traduzíveis
│   └── pt_BR.po              # Exemplo: tradução para português
├── scripts/                   # Scripts auxiliares (opcional)
├── tests/                     # Testes unitários (opcional)
└── README.md                  # Documentação do projeto
```

### Exemplo básico de `CMakeLists.txt`:
```cmake
cmake_minimum_required(VERSION 3.20)
project(adwaita LANGUAGES C)

# Dependências ADWAITA
find_package(PkgConfig REQUIRED)
pkg_check_modules(ADWAITA REQUIRED libadwaita-1)

# Configuração do projeto
include_directories(include)
add_executable(${PROJECT_NAME}
    src/main.c
    src/window.c
)

# Vincula libadwaita-1
target_link_libraries(${EXECUTABLE_NAME} PRIVATE ${ADWAITA_LIBRARIES})

```

### Recursos adicionais:
1. **Arquivos `.ui` (GTK Builder)**:
   - Coloque na pasta `ui/` e carregue em tempo de execução com `gtk_builder_add_from_file()`.

2. **CSS para estilização**:
   - Carregue arquivos da pasta `style/` com `gtk_css_provider_load_from_path()`.

3. **Recursos embutidos (GResource)**:
   - Crie um arquivo `resources.xml` na raiz e use `glib-compile-resources` para empacotar UI/CSS/ícones em um binário.

4. **Build com CMake**:
   ```bash
   mkdir build && cd build
   cmake ..
   make
   ```

5. **Organização de includes**:
   - Use `#include "app/window.h"` nos arquivos `.c` para cabeçalhos locais.

Essa estrutura mantém o código organizado e escalável. Para projetos maiores, considere dividir `src/` em módulos (ex: `src/core/`, `src/gui/`).
