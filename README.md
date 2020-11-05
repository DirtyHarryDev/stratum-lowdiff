# Stratum for YiiMP
with yescrypt - yescryptR8 - yescryptR16 - yescryptR32 support trimmed for Goldcash

## ▶️ Installation

Requires a YiiMP Server installation.

```
git clone https://github.com/DirtyHarryDev/stratum-yescrypt.git
```

* Compile
```
cd stratum-yescrypt/iniparser
make
cd ..
make
```

* Move stratum file
```
sudo mv stratum /home/yiimp-data/yiimp/site/stratum/stratum_yescrypt
```

After run addport modify run.sh with stratum_yescrypt
