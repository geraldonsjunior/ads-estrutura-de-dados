
/* =========================================
   ATUALIZAÇÃO AUTOMÁTICA DO ANO
   ========================================= */

const elementoAno = document.getElementById("ano-atual");

if (elementoAno) {
    elementoAno.textContent = new Date().getFullYear();
}


/* =========================================
   MENU RESPONSIVO
   ========================================= */

const botaoMenu = document.querySelector(".menu-toggle");
const menuPrincipal = document.querySelector("#menu-principal");

if (botaoMenu && menuPrincipal) {

    // Abre e fecha o menu ao clicar no botão.
    botaoMenu.addEventListener("click", () => {

        const estaAberto =
            botaoMenu.getAttribute("aria-expanded") === "true";

        botaoMenu.setAttribute(
            "aria-expanded",
            String(!estaAberto)
        );

        botaoMenu.setAttribute(
            "aria-label",
            estaAberto ? "Abrir menu" : "Fechar menu"
        );

        menuPrincipal.classList.toggle("ativo", !estaAberto);

    });


    // Fecha o menu depois que um link é selecionado.
    menuPrincipal.querySelectorAll("a").forEach((link) => {

        link.addEventListener("click", () => {

            botaoMenu.setAttribute("aria-expanded", "false");
            botaoMenu.setAttribute("aria-label", "Abrir menu");

            menuPrincipal.classList.remove("ativo");

        });

    });

}
