import { Restaurant } from "../model/restaurant";

export const restaurants: Restaurant[] = [
    {
        nombre: "Aire del Mar",
        descripcion: "Aire del Mar es nuestro restaurante principal donde podrás disfrutar de un alucinante buffet, ensaladas, postres y muchos platillos deliciosos.",
        imagen: "img/aire del mar.jpg",
        horarios: ["Desayuno Buffet:    7:00 a.m. – 11:00 a.m.",
            "Comida Buffet:          1:00 p.m. – 4:00 p.m.",
            "Cena Buffet:             6:30 p.m. – 10:00 p.m.",
            "Hora del Té:           5:00 p.m. – 6:00 p.m."]
    },
    {
        nombre: "Guakamajazz",
        descripcion: "Disfruta el sonido de las olas y los espectaculares atardeceres. Este hermoso restaurante al aire libre protegido por una palapa ofrece un servicio a la carta de especialidad italiana que seguramente satisfará cualquier gusto.",
        imagen: "img/guakamajazz.jpg",
        horarios: ["<span>Cena de Especialidad Italiana</span><br>Lunes, Jueves y Sábado (Previa reservación)<br>6:30 p.m. – 10:00 p.m.",
            "Cena Sunset<br>Martes (Previa reservación – Solo Adultos)<br> 7:00 p.m. – 8:00 p.m."
        ]
    },
    {
        nombre: "Snack Bar",
        descripcion: "Este maravilloso snack bar es popular entre niños y adultos. Además de tener uno de los lugares más bellos del hotel por su proximidad al océano, Snack Bar ofrece una amplia variedad de alimentos y platillos que seguramente amarás. Siéntate y experimenta la hermosa vista y disfrute de nuggets de pollo, hot dogs, nachos, hamburguesas, papas fritas y otras deliciosos platillos.",
        imagen: "img/bar hurakenna.jpg",
        horarios: ["12:00 p.m. – 5:00 p.m."]
    },
]