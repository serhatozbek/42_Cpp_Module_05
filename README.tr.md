# C++ Modül 05 — 42 Piscine

Bürokratik ofis simülasyonu. Dört aşamalı egzersiz: özel istisna tasarımı, kalıtım, polimorfizm ve factory pattern.

| Ex | Sınıf | Konsept |
|---|---|---|
| ex00 | `Bureaucrat` | Özel istisnalar (`std::exception`) |
| ex01 | `Form` | Sınıf birleştirme, yetki doğrulama |
| ex02 | `AForm` + 3 form | Soyut sınıf, kalıtım, polimorfizm |
| ex03 | `Intern` | Factory pattern |

**Kazanımlar:**
- `std::exception`'dan türeyen özel istisna sınıfları ve `what()` override
- `protected` ile alt sınıflara açık, dışarıya kapalı erişim
- Soyut sınıf ve `= 0` ile pure virtual metod
- Virtual destructor ile polymorphic yıkım
- `Intern::makeForm()` ile string-to-object factory

## Derleme

```bash
cd cpp5/ex02 && make && ./bureaucrat
```

---

⚠️ **Sorumluluk Reddi**
Bu repository'deki çözümler tamamen eğitim ve portföy amaçlıdır. 42'nin onur kuralları gereği, Common Core sürecindeki öğrencilerin çözümleri birebir kopyalaması kesinlikle yasaktır. Buradaki kodlar, bu modülü tamamlamış biri olarak gelişimi göstermek ve gelecekteki projeler için bir referans noktası oluşturmak amacıyla paylaşılmıştır.
