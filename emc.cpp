#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;


void criar_initel(string home, string usuario, string diretorio, string arquivo){
  string caminho = "/" + home + "/" + usuario + "/" + diretorio + "/" + arquivo;
  ofstream initEl(caminho);
  initEl << ";; Remove bars" << endl;
  initEl << "(menu-bar-mode -1)" << endl;
  initEl << "(tool-bar-mode -1)" << endl;
  initEl << "(scroll-bar-mode -1)" << endl;
  initEl << "" << endl;
  initEl << "(global-display-line-numbers-mode)" << endl;
  initEl << ";; Backu directory" << endl;
  initEl << "(setq" << endl;
  initEl << " backup-by-copying t" << endl;
  initEl << " backup-directory-alist" << endl;
  initEl << " '((\".\" . \"~/.emacs.d/saves/\"))" << endl;
  initEl << " delete-old-versions t" << endl;
  initEl << " kept-new-versions 6" << endl;
  initEl << " kept-old-versions 2" << endl;
  initEl << " version-control t" << endl;
  initEl << " )" << endl;
  initEl << "" << endl;
  initEl << "(setq-default tab-width 4)" << endl;
  initEl << "" << endl;
  initEl << ";; Themes" << endl;
  initEl << "" << endl;
  initEl << "(add-to-list 'custom-theme-load-path \"~/.emacs.d/themes/timu-caribbean-theme-main\")" << endl;
  initEl << "(custom-set-variables" << endl;
  initEl << " ;; custom-set-variables was added by Custom." << endl;
  initEl << " ;; If you edit it by hand, you could mess it up, so be careful." << endl;
  initEl << " ;; Your init file should contain only one such instance." << endl;
  initEl << " ;; If there is more than one, they won't work right." << endl;
  initEl << " '(custom-enabled-themes '(timu-caribbean))" << endl;
  initEl << " '(custom-safe-themes" << endl;
  initEl << "   '(\"4df2cb7ac1a6a1651a5a288f7ae8b475b1b821641849b348474e25d5549bd2d9\" default))" << endl;
  initEl << " '(package-selected-packages '(php-mode markdown-mode python-mode auto-correct)))" << endl;
  initEl << "(custom-set-faces" << endl;
  initEl << " ;; custom-set-faces was added by Custom." << endl;
  initEl << " ;; If you edit it by hand, you could mess it up, so be careful." << endl;
  initEl << " ;; Your init file should contain only one such instance." << endl;
  initEl << " ;; If there is more than one, they won't work right." << endl;
  initEl << " )" << endl;
  initEl << "" << endl;
  initEl << "(set-face-attribute 'default nil :height 150)" << endl;
  initEl << "" << endl;
  initEl << ";; PACKAGES MANUALLY INSTALLED" << endl;
  initEl << "(add-to-list 'load-path \"~/.emacs.d/packages/auto-complete\")" << endl;
  initEl << "(require 'auto-complete)" << endl;
  initEl << "(global-auto-complete-mode t)" << endl;
  initEl << "" << endl;
  initEl << "(add-to-list 'load-path \"~/.emacs.d/packages/popup-el\")" << endl;
  initEl << "(require 'popup)" << endl;
  initEl << "" << endl;
  initEl << ";;(add-to-list 'load-path \"~/.emacs.d/packages/tabnine\")" << endl;
  initEl << ";;(require 'tabnine)" << endl;
  initEl << "" << endl;
  initEl << ";; REPOSITORYS;" << endl;
  initEl << "(require 'package)" << endl;
  initEl << "(add-to-list 'package-archives '(\"melpa\" . \"https://melpa.org/packages/\") t)" << endl;
  initEl << "(add-to-list 'package-archives '(\"melpa\" . \"https://stable.melpa.org/packages/\") t)" << endl;
  initEl << "(package-initialize)" << endl;
  initEl << "" << endl;

  initEl.close();
}

int main(void){
  const char* user = "USER";
  const char* value = getenv(user);
  criar_initel("/home/", value, "/.emacs.d/", "init.el");

  return 0;
}
