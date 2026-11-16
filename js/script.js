
// Seleciona o elemento que possui o ID ano-atual
const elementoAno = document.getElementById("ano-atual");

// Obtém o ano atual do computador
const anoAtual = new Date().getFullYear();

// Atualiza o conteúdo do elemento HTML
elementoAno.textContent = anoAtual;
