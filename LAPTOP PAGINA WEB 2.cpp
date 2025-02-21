import { useState } from 'react';
import { Button } from "@/components/ui/button";
import { Card, CardContent } from "@/components/ui/card";
import { ShoppingCart, Trash } from "lucide-react";
import { motion } from "framer-motion";

export default function SalesPage() {
  const [cart, setCart] = useState([]);

  const addToCart = (product) => {
    setCart((prevCart) => {
      const existingItem = prevCart.find(item => item.id === product.id);
      if (existingItem) {
        return prevCart.map(item =>
          item.id === product.id ? { ...item, quantity: item.quantity + 1 } : item
        );
      }
      return [...prevCart, { ...product, quantity: 1 }];
    });
  };

  const removeFromCart = (productId) => {
    setCart((prevCart) => prevCart.filter(item => item.id !== productId));
  };

  const categories = [
    { name: "Laptops", brands: [
      { name: "HP", models: [
        { id: 1, name: "HP Spectre x360", price: "S/. 5799.99", image: "https://example.com/hp-spectre.jpg", specs: "Intel i7, 16GB RAM, 512GB SSD, 13.3\" 4K Touch" },
        { id: 2, name: "HP Pavilion 15", price: "S/. 3299.99", image: "https://example.com/hp-pavilion.jpg", specs: "Intel i5, 8GB RAM, 256GB SSD, 15.6\" Full HD" },
        { id: 3, name: "HP Envy 14", price: "S/. 4599.99", image: "https://example.com/hp-envy.jpg", specs: "Ryzen 7, 16GB RAM, 512GB SSD, 14\" Full HD" }
      ] },
      { name: "ASUS", models: [
        { id: 4, name: "ASUS ROG Zephyrus G14", price: "S/. 7599.99", image: "https://example.com/asus-rog.jpg", specs: "Ryzen 9, 32GB RAM, 1TB SSD, RTX 3060" },
        { id: 5, name: "ASUS VivoBook 15", price: "S/. 3299.99", image: "https://example.com/asus-vivobook.jpg", specs: "Intel i5, 8GB RAM, 512GB SSD, 15.6\" Full HD" }
      ] },
      { name: "Acer", models: [
        { id: 6, name: "Acer Predator Helios 300", price: "S/. 6299.99", image: "https://example.com/acer-predator.jpg", specs: "Intel i7, 16GB RAM, 512GB SSD, RTX 2060" },
        { id: 7, name: "Acer Aspire 5", price: "S/. 2899.99", image: "https://example.com/acer-aspire.jpg", specs: "Ryzen 5, 8GB RAM, 256GB SSD, 15.6\" Full HD" }
      ] },
      { name: "Lenovo", models: [
        { id: 8, name: "Lenovo Legion 5", price: "S/. 5899.99", image: "https://example.com/lenovo-legion.jpg", specs: "Ryzen 7, 16GB RAM, 512GB SSD, RTX 3060" },
        { id: 9, name: "Lenovo ThinkPad X1 Carbon", price: "S/. 6999.99", image: "https://example.com/lenovo-thinkpad.jpg", specs: "Intel i7, 16GB RAM, 1TB SSD, 14\" UHD" }
      ] }
    ] },
    { name: "Impresoras", brands: [
      { name: "Epson", models: [
        { id: 10, name: "Epson L3150", price: "S/. 899.99", image: "https://example.com/epson-l3150.jpg", specs: "Impresión inalámbrica, EcoTank, alta eficiencia" }
      ] },
      { name: "Brother", models: [
        { id: 11, name: "Brother DCP-T520W", price: "S/. 849.99", image: "https://example.com/brother-dcp.jpg", specs: "Sistema de tinta continua, impresión WiFi" }
      ] },
      { name: "Canon", models: [
        { id: 12, name: "Canon PIXMA G2160", price: "S/. 799.99", image: "https://example.com/canon-g2160.jpg", specs: "Alta resolución, impresión fotográfica" }
      ] }
    ] }
  ];

  return (
    <div className="p-6">
      {categories.map((category) => (
        <div key={category.name}>
          <h2>{category.name}</h2>
          {category.brands?.map((brand) => (
            <div key={brand.name}>
              <h3>{brand.name}</h3>
              {brand.models.map((product) => (
                <Card key={product.id}>
                  <CardContent>
                    <img src={product.image} alt={product.name} />
                    <h4>{product.name}</h4>
                    <p>{product.specs}</p>
                    <p>{product.price}</p>
                    <Button onClick={() => addToCart(product)}>
                      <ShoppingCart /> Agregar al carrito
                    </Button>
                  </CardContent>
                </Card>
              ))}
            </div>
          ))}
        </div>
      ))}
      <div>
        <h2>Carrito de Compras</h2>
        {cart.length > 0 ? (
          cart.map((item) => (
            <div key={item.id}>
              <p>{item.name} - {item.price} (x{item.quantity})</p>
              <Button onClick={() => removeFromCart(item.id)}>
                <Trash /> Eliminar
              </Button>
            </div>
          ))
        ) : (
          <p>El carrito está vacío</p>
        )}
      </div>
    </div>
  );
}
