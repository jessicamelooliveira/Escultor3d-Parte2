#!/bin/bash

#Atualizar data de modificação
README_PATH="README.md"
DATE=$(date '+%d de %B de %Y, %H:%M')

sed -i "s/Última modificação:.*/Última modificação: $DATE/" $README_PATH

git add $README_PATH
git commit -m "Atualização da data da última modificação"
git push origin master

#Enviar alterações para o git
echo "Digite a mensagem de commit"
read mensagem

git add .
git commit -m "$mensagem"
git push origin master
