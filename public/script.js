document.addEventListener('DOMContentLoaded', () => {
  const CONTACT_LINK = 'https://t.me/shvecarsky';
  const tg = window.Telegram ? window.Telegram.WebApp : null;

  // ---------- Telegram WebApp init ----------
  if (tg) {
    try { tg.ready(); } catch (e) {}
    try { tg.expand(); } catch (e) {}
    try { tg.setHeaderColor('#0a0f1d'); } catch (e) {}
    try { tg.setBackgroundColor('#0a0f1d'); } catch (e) {}
    try { tg.enableClosingConfirmation(); } catch (e) {}
  }

  // ---------- Scroll-reveal for sections ----------
  const sections = document.querySelectorAll('.fade-in-section');

  if ('IntersectionObserver' in window) {
    const observer = new IntersectionObserver(
      (entries) => {
        entries.forEach((entry) => {
          if (entry.isIntersecting) {
            entry.target.classList.add('visible');
            observer.unobserve(entry.target);
          }
        });
      },
      { threshold: 0.15, rootMargin: '0px 0px -40px 0px' }
    );

    sections.forEach((section) => observer.observe(section));
  } else {
    sections.forEach((section) => section.classList.add('visible'));
  }

  // ---------- CTA button(s) ----------
  const ctaButtons = document.querySelectorAll('.js-cta-button');

  ctaButtons.forEach((btn) => {
    btn.addEventListener('click', () => {
      if (tg && tg.HapticFeedback) {
        try { tg.HapticFeedback.impactOccurred('medium'); } catch (e) {}
      }

      if (tg && typeof tg.openTelegramLink === 'function') {
        try {
          tg.openTelegramLink(CONTACT_LINK);
          return;
        } catch (e) {}
      }

      window.open(CONTACT_LINK, '_blank');
    });
  });

  // ---------- Scroll hint ----------
  const scrollHint = document.getElementById('scrollHint');
  if (scrollHint) {
    scrollHint.addEventListener('click', () => {
      const target = document.getElementById('services');
      if (target) {
        target.scrollIntoView({ behavior: 'smooth', block: 'start' });
      }
    });
  }
});
