# yarensonmez-Seri-ve-Paralel-Matris-Carpimi
Visual Studio 2019 ortamında C++ diliyle yazılmıştır. Paralel programlama kısmı OpenMP ile gerçekleştirilmiştir.

Pandemi süresince Paralel Bilgisayarlar dersi dönem projesi olarak verilen bu projede
FLOAT ve DOUBLE değişkenlerinin seri ve paralel programlamadaki performanslara etkisi ve
paralel programlamanın kod performansına etkileri nxn'lik matrislerin çarpımı üzerinden koda dökülmüştür.

Bu projenin Visual Studio ortamında çalışabilmesi için Studio derleyicisindeki OpenMP desteğinin
aktifleştirilmesi gerekir. 2019 versiyonu için en üstte yer alan sekmelerden
"Proje > Proje Özellikleri > C / C++ > Dil > Open MP Desteği"
şeklinde ilerledikten sonra “Evet” seçeneği ile aktifleştirilmesi sağlanabilir.

OpenMP, paralel programlamada kullanılan; programda paralel gibi çalışıp dallanan, işlem bitince de tekrar birleşen, 
hem veriyi hem de görevi paralelleştirmeye yarayan bir API'dir. Programcının çeşitli paylaşımlı değişkenlere,döngü içindeki her cycle'daki 
değişkenlerin birbiriyle bağlantılarına dikkat etmesi,ona göre pragmaları düzenlemesi,işlemi corelara dağıtırken işin analizini iyi yapması
ve nerede ne zaman kullanması gerektiğini iyi analiz etmesi gereklidir çünkü bu işlem yanlış gerçekleştirilirse verim elde edeyim derken seri 
bir sonuçtan daha aşağısına düşülebilir.

Paralel programlamada yapılacak bir iş, birden çok iş bölümlerine ayrılır ve her iş bölümünde bulunan sonuçlar 
bir yerde toplanır ve bu şekilde, bu işlerin daha kısa zamanda ve daha hızlı bir şekilde yapılmasına olanak 
sağlanır.Paralel hesaplamayla sonuca daha hızlı ulaşmanın yanında, iş bölümleri aynı anda işletilerek eş zamanlı 
olarak işlemlerin yapılmasıyla performans da arttırılır. Bu bağlamda projeyi gerçekleştirken görmem gereken sonuç
paralel programlamanın seriden daha hızlı olmasıdır.

Ben bu projeyi 1K, 2K, 3K, 4K ve 5K'lık matrisler için koştum. Evet, gerçekten de seri ve paraleli 
genel olarak karşılaştıracak olursak her açıdan paralel programlama seriden daha hızlıdır.
Seride de float için 1K, 2K ve 5K az ya da çok farkla bile olsa daha hızlı, 3K ve 4K için ise double'ın daha hızlı olduğu görülmektedir.
Bu durum uyguladığım algoritma ya da bilgisayarın sistem özelliklerinden kaynaklanıyor olabilir.
