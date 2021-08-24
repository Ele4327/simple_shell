#!/bin/bash

## AUTHORS
    #Juan Duque
    #Sebastian Garzon
    #Laura Cadavid

#Colours
greenColour="\e[0;32m\033[1m"
endColour="\033[0m\e[0m"
redColour="\e[0;31m\033[1m"
blueColour="\e[0;34m\033[1m"
yellowColour="\e[0;33m\033[1m"
purpleColour="\e[0;35m\033[1m"
turquoiseColour="\e[0;36m\033[1m"
grayColour="\e[0;37m\033[1m"
Cyan="\033[0;36m"
nc="\e[0m"

#ROOT PRIVILEGIES
if [[ $EUID -ne 0 ]]; then
        echo -e "$red You don't have Root privilegies, execute the script as root.$nc"
        exit 1
fi

#RECEP INPUT KEYBOARD
sleep 1
trap ctrl_c INT 
function ctrl_c(){
    echo -e "\n${redColour}[!] saliendo ...\n ${sendColour}"
    tput cnorm; exit 127
}
echo -ne "\n\n\n"

sleep 0.05
function banner {
clear
echo -e "\t ${yellowColour}  (\`-').->  (\`-').->  (\`-')  _                   " && sleep 0.05
echo -e "\t   ( OO)_    (OO )__   ( OO).-/    <-.       <-.      " && sleep 0.05
echo -e "\t   (_)--\_)  ,--. ,'-' (,------.  ,--. )    ,--. )    ${endColour} "&& sleep 0.05
echo -e "\t ${redColour}  /    _ /  |  | |  |  |  .---'  |  (\`-')  |  (\`-')"&& sleep 0.05
echo -e "\t   \_..\`--.  |  \`-'  | (|  '--.   |  |OO )  |  |OO )"&& sleep 0.05
echo -e "\t   .-._)   \ |  .-.  |  |  .--'  (|  '__ | (|  '__ |  ${endColour} "&& sleep 0.05
echo -e "\t ${Cyan}  \       / |  | |  |  |  \`---.  |     |'  |     |' "&& sleep 0.05
echo -e "\t    \`-----'  \`--' \`--'  \`------'  \`-----'   \`-----'${endColour} "&& sleep 0.05
sleep 0.05
echo -ne "\n"
echo -e "\t${yellowColour}(${endColour}${grayColour}Hecho por ${endColour}${blueColour}Juan Duque - Sebastian Garzon - Laura Cadavid${endColour}${yellowColour})${endColour}"
echo -e "${Cyan}====>===>=======>======>=====>====>====>=====>=======>======>=====>====> ${endColor}"
echo -ne "\n"
}

#CALL FUNCTION BANNER INIT
banner

#FUNCTION PREVIEW HELP PANEL
function helpPanel()
{
    echo -e "\n${grayColor}Use for Installer ----->\n\t\t\t ${blueColour} ./sh-install.sh -i${endColour} ${yellowColour}[${endColour} parameter ${yellowColour}]${endColour} ${endColour}${yellowColor}\t${endcolor}"
    for i in $(seq 1 80);do echo -ne "${greenColour}-"; done; echo -ne "${endColour}"
    echo -ne "\n\t${purpleColour} [-i]\t Interactive Mode ${endColor}\t${redColour}\t Interpret any commands${endColor}\n\n"
    echo -ne "\t${blueColour} \t[ -i run       ]\t${endColor}${redColour}\t.... \tRun Program${endColor}\n"
    echo -ne "\t${blueColour} \t[ -i install   ]\t ${endColor}${redColour}\t.... \tInstall Shell${endColor}\n"
    echo -ne "\t${blueColour} \t[ -i read      ]\t ${endColor}${redColour}\t.... \tView README.md ${endColor}\n"
    echo -ne "\t${blueColour} \t[ -i help      ]\t ${endColor}${redColour}\t.... \tHelp Panel Commands${endColor}\n" 
    echo -ne "\t${blueColour} \t[ -i authors   ]\t ${endColor}${redColour}\t.... \tMore Infor Authors${endColor}\n"
    echo -ne "\t${blueColour} \t[ -i manuals   ]\t ${endColor}${redColour}\t.... \tInfo Manuals${endColor}\n"
    echo -ne "\t${blueColour} \t[ -i depend    ]\t ${endColor}${redColour}\t.... \tInstall ALl Dpendences${endColor}\n"
    echo -ne "\t${blueColour} \t[ -i uninstall ]\t ${endColor}${redColour}\t.... \tUninstall Program${endColor}\n"
    tput cnorm; exit 0
}


function compile()
{   
    sleep 2
    echo -e "\n${yellowColour} Compilating Shelling ${endColour}....${greenColour}[✔]${endColour}\n\t"
    make comp-holb_;sudo cp hsh /usr/local/sbin
    sleep 3
    echo -e "\n${yellowColour} Compilating Finished${endColour} ....${greenColour}[✔]${endColour}"
    sleep 3
}

#FUNCTIONS OF GREATS
function thanks()
{
    echo -e "${turquoiseColour}Thank you very much for installing the software..${endColour}${greenColour}..[✔]${endColour}"
    banner
    helpPanel
}

#FUNCTION RUN PROGRAM BASIC SHELL
function _run()
{
    hsh
}

#FUNCTION READ FILE README
function _read()
{
    clear
    cat README.md
}

function install_dep()
{
    clear
    sudo apt-get install make
    sudo apt-get install top
    sudo apt-get install gcc
    sudo apt-get install gdb

    echo -e "\n${cyanColour}Install dependences Complete${endColour}${greenColour}[✔]${endColour}\n"
}

#FUNCTION OF THE INSTALL
function install_ ()
{

#VERIFY IF THE INSTALL IS CORRECT
sudo ls /usr/local/sbin | grep "hsh" >> tmp_.tmp

if [ "$(cat tmp_.tmp | wc -l)" == "1" ]; then
    echo -e "Is already installed ----[✔]\n"
    hsh
else
    echo -e "${cyanColour}Installation Requiered ${endcolour}${redColour}........... [!]${endColour}\n\n"
fi
if [ "$(cat tmp_.tmp | wc -l)" != "1" ]; then
    #Sysupdate
    sudo apt --fix-broken install -y
    sudo apt-get update -y;sudo apt-get upgrade -y ;clear
    #Compila
    compile
    sudo cp sh-install.sh /usr/local/sbin; cd /usr/local/sbin; mv sh-install.sh _shell 
    
    echo -e "${turquoiseColour}the installation was correct.${endColour}${greenColour}[✔]${endColour}"
    thanks
fi
rm -r tmp_.tmp
tput cnorm; exit 0
}

parameter_counter=0; while getopts "i:" arg; do
    case $arg in
        i) running=$OPTARG; let parameter_counter+=1;;
    esac
done

tput civis

if [ "$parameter_counter" -eq 0 ]; then
    helpPanel
else
    if [ "$(echo $running)" == "run" ]; then
        _run
         exit 0
    elif [ "$(echo $running)" == "help" ]; then
        helpPanel
    elif [ "$(echo $running)" == "read" ]; then
        _read
    elif [ "$(echo $running)" == "install" ]; then
        install_
    elif [ "$(echo $running)" == "authors" ]; then
        cat MANUALS/AUTHORS
    elif [ "$(echo $running)" == "manuals" ]; then
        ls MANUALS
        echo -e "\n\t\t${redColour}Usage: ${endColour} ${purpleColour} man${blueColour}_${endCOlour}[ manual ]${endColour}"
    elif [ "$(echo $running)" == "man_shell" ]; then
        man MANUALS/./man_1_simple_shell
    elif [ "$(echo $running)" == "man_cd" ]; then
        man MANUALS/./man_cd
    elif [ "$(echo $running)" == "uninstall" ]; then
        echo -e "\n${redColour}[!] Uninstalling ...\n ${sendColour}"
        sudo rm -r /usr/local/sbin/*;make clean;make clean_tops
        echo -e "\n${redColour}[✔] Uninstalling Complete ...\n ${sendColour}"
    elif [ "$(echo $running)" == "depend" ]; then
        install_dep
    else
        exit 1
    fi
fi