:root {
  --bg-deep: #0a0f1d;
  --neon-cyan: #00f2fe;
  --neon-blue: #4facfe;
  --glass-bg: rgba(255, 255, 255, 0.045);
  --glass-border: rgba(0, 242, 254, 0.16);
  --safe-top: env(safe-area-inset-top, 0px);
  --safe-bottom: env(safe-area-inset-bottom, 0px);
}

* {
  -webkit-tap-highlight-color: transparent;
  box-sizing: border-box;
}

html, body {
  background-color: var(--bg-deep);
  overflow-x: hidden;
}

body {
  min-height: 100vh;
  padding-top: var(--safe-top);
  color: #e8f1ff;
}

html {
  scroll-behavior: smooth;
  scroll-padding-top: var(--safe-top);
}

::-webkit-scrollbar {
  width: 0px;
  background: transparent;
}

button {
  font-family: inherit;
  border: none;
  cursor: pointer;
  -webkit-appearance: none;
  appearance: none;
}

button:focus-visible,
a:focus-visible {
  outline: 2px solid var(--neon-cyan);
  outline-offset: 3px;
  border-radius: 4px;
}

/* ---------- Ambient glow orbs ---------- */

.glow-orb {
  position: fixed;
  border-radius: 50%;
  filter: blur(90px);
  pointer-events: none;
  z-index: 0;
  will-change: transform;
}

.orb-1 {
  width: 280px;
  height: 280px;
  background: var(--neon-cyan);
  top: -90px;
  left: -70px;
  opacity: 0.35;
  animation: float1 13s ease-in-out infinite;
}

.orb-2 {
  width: 240px;
  height: 240px;
  background: var(--neon-blue);
  bottom: 12%;
  right: -100px;
  opacity: 0.3;
  animation: float2 15s ease-in-out infinite;
}

.orb-3 {
  width: 220px;
  height: 220px;
  background: #6f6bff;
  top: 42%;
  left: 55%;
  opacity: 0.18;
  animation: float3 17s ease-in-out infinite;
}

@keyframes float1 {
  0%, 100% { transform: translate(0, 0) scale(1); }
  50% { transform: translate(35px, 45px) scale(1.1); }
}

@keyframes float2 {
  0%, 100% { transform: translate(0, 0) scale(1); }
  50% { transform: translate(-30px, -25px) scale(1.12); }
}

@keyframes float3 {
  0%, 100% { transform: translate(-50%, 0) scale(1); }
  50% { transform: translate(-50%, -35px) scale(1.15); }
}

/* ---------- Glass surfaces ---------- */

.glass-card {
  background: var(--glass-bg);
  backdrop-filter: blur(20px);
  -webkit-backdrop-filter: blur(20px);
  border: 1px solid var(--glass-border);
  border-radius: 22px;
  box-shadow: 0 8px 32px rgba(0, 0, 0, 0.35), inset 0 1px 0 rgba(255, 255, 255, 0.04);
  transition: transform 0.25s ease, border-color 0.25s ease;
}

.glass-card:active {
  transform: scale(0.985);
  border-color: rgba(0, 242, 254, 0.35);
}

.glass-pill {
  background: rgba(0, 242, 254, 0.08);
  backdrop-filter: blur(14px);
  -webkit-backdrop-filter: blur(14px);
  border: 1px solid rgba(0, 242, 254, 0.28);
  border-radius: 999px;
}

.icon-badge {
  background: linear-gradient(135deg, rgba(0, 242, 254, 0.16), rgba(79, 172, 254, 0.05));
  border: 1px solid rgba(0, 242, 254, 0.25);
  box-shadow: 0 0 18px rgba(0, 242, 254, 0.14);
}

/* ---------- CTA button ---------- */

.cta-scrim {
  background: linear-gradient(to top, rgba(10, 15, 29, 0.97) 55%, rgba(10, 15, 29, 0));
  padding-bottom: calc(var(--safe-bottom) + 18px);
}

.cta-wrapper {
  padding-bottom: 2px;
}

.cta-button {
  background: linear-gradient(120deg, var(--neon-cyan), var(--neon-blue));
  color: #071022;
  box-shadow: 0 0 22px rgba(0, 242, 254, 0.45), 0 0 46px rgba(79, 172, 254, 0.22);
  transition: transform 0.18s ease, box-shadow 0.3s ease;
  animation: pulse-glow 2.8s ease-in-out infinite;
}

.cta-button:active {
  transform: scale(0.965);
}

@keyframes pulse-glow {
  0%, 100% { box-shadow: 0 0 22px rgba(0, 242, 254, 0.45), 0 0 46px rgba(79, 172, 254, 0.22); }
  50% { box-shadow: 0 0 32px rgba(0, 242, 254, 0.7), 0 0 64px rgba(79, 172, 254, 0.38); }
}

/* ---------- Hero entrance (single orchestrated sequence) ---------- */

@keyframes heroFadeUp {
  from { opacity: 0; transform: translateY(18px); }
  to { opacity: 1; transform: translateY(0); }
}

.hero-anim {
  opacity: 0;
  animation: heroFadeUp 0.8s cubic-bezier(0.16, 1, 0.3, 1) forwards;
}

.hero-anim-delay-1 { animation-delay: 0.12s; }
.hero-anim-delay-2 { animation-delay: 0.24s; }
.hero-anim-delay-3 { animation-delay: 0.36s; }

@keyframes bounceSoft {
  0%, 100% { transform: translateY(0); opacity: 0.55; }
  50% { transform: translateY(6px); opacity: 1; }
}

.scroll-hint {
  animation: bounceSoft 2.2s ease-in-out infinite;
  animation-delay: 0.9s;
  background: transparent;
}

/* ---------- Scroll-reveal for sections ---------- */

.fade-in-section {
  opacity: 0;
  transform: translateY(20px);
  transition: opacity 0.6s ease, transform 0.6s ease;
}

.fade-in-section.visible {
  opacity: 1;
  transform: translateY(0);
}

/* ---------- Small icon float ---------- */

@keyframes iconFloat {
  0%, 100% { transform: translateY(0); }
  50% { transform: translateY(-5px); }
}

.icon-float {
  animation: iconFloat 3.6s ease-in-out infinite;
}

/* ---------- Accessibility: respect reduced motion ---------- */

@media (prefers-reduced-motion: reduce) {
  *, *::before, *::after {
    animation-duration: 0.001ms !important;
    animation-iteration-count: 1 !important;
    transition-duration: 0.001ms !important;
    scroll-behavior: auto !important;
  }

  .hero-anim, .fade-in-section {
    opacity: 1;
    transform: none;
  }
}
