package cifrarImagen;

import imagenes.JFrameImagen;
import java.awt.Color;
import java.awt.Image;
import java.awt.image.BufferedImage;
import java.math.BigInteger;
import java.nio.ByteBuffer;
import java.nio.ByteOrder;
import java.util.Random;

/**
 *
 * @author david
 */
public class XOR {
    private Image original;
    private Image cifrada;
    
    public XOR(Image original) {
        this.original = original;
    }
    
    public Image cifrarImagen() {
        int ancho = this.original.getWidth(null);
        int alto = this.original.getHeight(null);
        BufferedImage nueva = new BufferedImage(ancho, alto, BufferedImage.TYPE_INT_RGB);
        // De la original se requieren los pixeles
        BufferedImage o = imagenes.ImageManager.toBufferedImage(original);
        for (int i = 0; i < ancho; i++) {
            for (int j = 0; j < alto; j++) {
                Color color = new Color(o.getRGB(i, j));
                // Obtener los colores cifrados
                int rojo = obtenerColorCifrado(color.getRed());
                int verde = obtenerColorCifrado(color.getGreen());
                int azul = obtenerColorCifrado(color.getBlue());
                System.out.println(rojo + " " + verde + " " + azul);
                Color cifrado = new Color(rojo, verde, azul);
                nueva.setRGB(i, j, cifrado.getRGB());
            }
        }
        return imagenes.ImageManager.toImage(nueva);
    }
    
    private int obtenerColorCifrado(int color) {
        Random r = new Random();
        int valorAletorio8Bits = r.nextInt(256);
        return color ^ valorAletorio8Bits;
    }
    
    public static void main(String args[]) {
        Image original = imagenes.ImageManager.openImage();
        XOR xor = new XOR(original);
        // Se muestra en un frame
        JFrameImagen fo = new JFrameImagen(original);
        fo.setVisible(true);
        fo.setTitle("Original");
        
        Image cifrada = xor.cifrarImagen();
        // Se muestra en un frame
        JFrameImagen fc = new JFrameImagen(cifrada);
        fc.setVisible(true);
        fc.setTitle("Cifrada");
    }
}
