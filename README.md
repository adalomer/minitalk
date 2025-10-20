# 🔌 Minitalk

42 okulunun sistem programlama projeleri serisinden **Minitalk**, süreçler arası iletişim (IPC) ve UNIX sinyalleri üzerine geliştirilmiş bir projedir.

## 📋 Proje Hakkında

Minitalk projesi, iki program arasında yalnızca UNIX sinyalleri (`SIGUSR1` ve `SIGUSR2`) kullanarak veri iletişimi sağlar. Bir sunucu ve bir istemci programından oluşur.

### ✨ Özellikler

- **Server**: PID'sini gösterir ve istemcilerden mesaj bekler
- **Client**: Sunucunun PID'sine string mesajlar gönderir
- **Binary İletişim**: Her karakter bit bit (`SIGUSR1` = 0, `SIGUSR2` = 1) iletilir
- **Unicode Desteği**: Tüm karakterleri destekler
- **Hızlı İletim**: Optimize edilmiş sinyal gönderimi

## 🚀 Kurulum

```bash
# Repoyu klonlayın
git clone https://github.com/kullaniciadi/minitalk.git
cd minitalk

# Derleyin
make

# Bonus versiyonu için
make bonus
```

## 💻 Kullanım

### Sunucuyu Başlatma

```bash
./server
```

Server başladığında PID'sini gösterecektir:

```
Server PID: 12345
Waiting for messages...
```

### İstemci ile Mesaj Gönderme

```bash
./client [SERVER_PID] "Mesajınız"
```

Örnek:

```bash
./client 12345 "Merhaba Dünya! 🌍"
```

## 🏗️ Proje Yapısı

```
minitalk/
├── Makefile
├── README.md
├── server.c          # Sunucu programı
├── client.c          # İstemci programı
├── minitalk.h        # Header dosyası
└── utils.c           # Yardımcı fonksiyonlar
```

## 🛠️ Teknik Detaylar

### Kullanılan Sistemler
- UNIX Sinyalleri (`SIGUSR1`, `SIGUSR2`)
- Bit manipülasyonu
- Signal handling (`sigaction`)

### İletişim Protokolü
1. Her karakter 8 bite dönüştürülür
2. Her bit bir sinyal olarak gönderilir
3. `SIGUSR1` → bit 0
4. `SIGUSR2` → bit 1
5. Sunucu bitleri birleştirerek karakteri oluşturur

## 📚 Bonus Özellikler

- ✅ Sunucu, her mesaj aldığında istemciye onay gönderir
- ✅ Unicode karakter desteği
- ✅ Çoklu istemci desteği

## ⚙️ Derleme Kuralları

```bash
make           # Zorunlu kısım
make bonus     # Bonus kısım
make clean     # Object dosyalarını temizle
make fclean    # Tüm derlenmiş dosyaları temizle
make re        # Yeniden derle
```

## 🧪 Test

```bash
# Basit test
./client [PID] "Test"

# Uzun mesaj testi
./client [PID] "Lorem ipsum dolor sit amet..."

# Unicode testi
./client [PID] "Hello 世界 🌍 مرحبا"

# Boş mesaj testi
./client [PID] ""
```

## 📖 Kaynaklar

- [Signal Handling](https://man7.org/linux/man-pages/man7/signal.7.html)
- [Bitwise Operations](https://en.wikipedia.org/wiki/Bitwise_operation)
- [Inter-Process Communication](https://en.wikipedia.org/wiki/Inter-process_communication)

## 👤 Geliştirici

**Ömer Ali Adalı**  
42 İntra: `omadali`

## 📄 Lisans

Bu proje 42 Network'ün eğitim amaçlı bir projesidir.

---

⭐ Projeyi beğendiyseniz yıldız vermeyi unutmayın!
