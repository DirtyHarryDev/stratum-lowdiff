# Stratum for YiiMP
with balloon - yescrypt - yescryptR8 - yescryptR16 - yescryptR32 support trimmed for low difficulty shares

## ▶️ Installation

Requires a YiiMP Server installation.

```
git clone https://github.com/DirtyHarryDev/stratum-lowdiff.git
```

* Compile
```
cd stratum-lowdiff/iniparser
make
cd ..
make
```

* Move stratum file
```
sudo mv stratum /home/yiimp-data/yiimp/site/stratum/stratum_lowdiff
```

After run addport modify run.sh with stratum_lowdiff
